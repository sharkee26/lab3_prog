#ifndef CUSTOM_VECTOR_H   
#define CUSTOM_VECTOR_H  
template<typename T>
class c_vector{
public:
    c_vector();
    ~c_vector();

    T& operator[](const size_t index);
    const T& operator[](const size_t index) const;

    c_vector(const c_vector<T>& another_vector);  
    c_vector(c_vector<T>&& another_vector) noexcept; 
    c_vector<T>& operator=(const c_vector<T> &);

    c_vector(size_t capacity);

    void push_back(const T& data);
    T pop_back();
    
    void reserve(size_t cpcty);
    size_t size();
    size_t getCapacity();
    size_t size() const;
    size_t getCapacity() const;
    class iterator{
        public:
        iterator(T* ptr) : current(ptr) {}
        T& operator*(){
            return *current;
        }
        bool operator!=(const iterator& other) const {
            return current != other.current;
        }
        iterator& operator++() {
            ++current;
            return *this;
        }
        private:
        T* current;
    };
    iterator begin();
    iterator end();
    void insert(iterator iter, T data);
    iterator erase(iterator iter);
private:
    T* vect;
    size_t size_vector;
    size_t capacity;
};

template<typename T>
c_vector<T>::c_vector(){
    size_vector=0;
    capacity=10;
    vect=new T[capacity];
}

template<typename T>
c_vector<T>::~c_vector() {
    if(vect!=nullptr)
        delete[]vect;
}

template<typename T>
T& c_vector<T>::operator[](const size_t index){
    if(index>=this->size_vector)
        throw std::invalid_argument("Index must be less than vector's size");
    return vect[index];
}

template<typename T>
const T& c_vector<T>::operator[](const size_t index)const{
    if(index>=this->size_vector)
        throw std::invalid_argument("Index must be less than vector's size");
    return vect[index];
}

template<typename T>
c_vector<T>::c_vector(const c_vector<T>& another_vector){
    if(vect!=nullptr){
        delete[]vect;
    }
    size_vector=another_vector.size();
    capacity=another_vector.getCapacity();
    vect=new T[capacity];
    for(size_t i=0;i<size_vector;i++){
        vect[i]=another_vector[i];
    }
}

template<typename T>
c_vector<T>::c_vector(c_vector<T>&& another_vector) noexcept{
    if(vect!=nullptr){
        delete[]vect;
    }
    size_vector=another_vector.size();
    capacity=another_vector.getCapacity();
    vect=new T[capacity];
    for(size_t i=0;i<size_vector;i++){
        vect[i]=another_vector[i];
    }

    another_vector.vect = nullptr;
    another_vector.size_vector = 0;
    another_vector.capacity = 0;
}
template<typename T>
c_vector<T>& c_vector<T>:: operator=(const c_vector<T> & another_vector){
    if(vect!=nullptr){
        delete[]vect;
    }
    this->size_vector=another_vector.size();
    this->capacity=another_vector.getCapacity();
    vect=new T[capacity];
    for(size_t i=0;i<size_vector;i++){
        vect[i]=another_vector[i];
    }
    return *this;
}
template<typename T>
c_vector<T>::c_vector(size_t capacity){
    this->capacity=capacity;
    this->size_vector=0;
    vect=new T[capacity];
}

template<typename T>
void c_vector<T>::push_back(const T& data){
    if(this->size_vector==this->capacity){
        if(this->capacity==0){
            reserve(10);
        }
        else{
            reserve(this->size_vector*2);
        }
    }
    vect[size_vector]=data;
    size_vector++;
}

template<typename T>
T c_vector<T>::pop_back(){
    if(this->size_vector<1){
        throw std::out_of_range("vector is empty");
    }
    T last_element=vect[size_vector-1];
    size_vector--;
    return last_element;
}

template<typename T>
void c_vector<T>::insert(iterator iter, T data){
    if(this->size_vector==this->capacity){
        if(this->capacity==0){
            reserve(10);
        }
        else{
            reserve(this->size_vector*2);
        }
    }
    size_vector++;
    for(auto it=iter;it!=end(); ++it){
        T next=*it;
        *it=data;
        data=next;
    }
}

template<typename T>
typename c_vector<T>::iterator c_vector<T>::erase(iterator iter){
    if(this->size_vector<1){
        throw std::out_of_range("vector is empty");
    }
    auto to_return=iter;
    size_vector--;
    for(auto it=iter;it!=end();++it){
        *it=*(++iter);
    }
    return to_return;
}

template<typename T>
void c_vector<T>::reserve(size_t cpcty){
    if(cpcty>size_vector){
        T* temp=new T[cpcty];
        for(size_t i=0;i<cpcty;i++){
            temp[i]=vect[i];
        }
        delete []vect;
        this->capacity=cpcty;
        vect=temp;
    }
}

template<typename T>
size_t c_vector<T>::size(){
    return this->size_vector;
}

template<typename T>
size_t c_vector<T>::getCapacity(){
    return this->capacity;
}

template<typename T>
size_t c_vector<T>::size() const {
    return this->size_vector;
}

template<typename T>
size_t c_vector<T>::getCapacity() const{
    return this->capacity;
}

template<typename T>
typename c_vector<T>::iterator c_vector<T>::begin(){
    return iterator(vect);
}

template<typename T>
typename c_vector<T>::iterator c_vector<T>::end(){
    return iterator(vect+size_vector);
}
#endif