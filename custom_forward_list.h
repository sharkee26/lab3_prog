#ifndef CUSTOM_FORWARD_LIST_H   
#define CUSTOM_FORWARD_LIST_H  

template<typename T>
class c_forward_list{
private:
    class Node{
        public:
            Node* p_next;
            T data;
            Node(T data=T(), Node *p_next=nullptr){
                this->data=data;
                this->p_next=p_next;
            }
    };
    
    size_t size_fl;
    Node*root;
public:
    class iterator{
    public:
        iterator(Node* ptr=nullptr){
            current=ptr;
        }
        T& operator*(){
            return current->data;
        }
        bool operator!=(const iterator& other) const {
            return current != other.current;
        }
        iterator& operator++() {
            current=current->p_next;
            return *this;
        }
    private:
        Node*current;
       
    };
    
    c_forward_list();
    ~c_forward_list();
    
    T& operator[](const size_t index);
    const T& operator[](const size_t index) const;
    
    c_forward_list(const c_forward_list<T>& another_list);  
    c_forward_list(c_forward_list<T>&& another_list) noexcept;
    c_forward_list<T>& operator=(const c_forward_list<T> &);

    iterator begin();
    iterator end();
    size_t size();
    void push_back(T data);
    void insert(int index, T data);
    T erase(size_t index);
};

template<typename T>
c_forward_list<T>::c_forward_list(){
    size_fl=0;
    root=nullptr;
}

template<typename T>
c_forward_list<T>::~c_forward_list(){
     while (root != nullptr) {
        Node* temp = root;          
        root = root->p_next;       
        delete temp;               
    }
    
}

template<typename T>
size_t c_forward_list<T>::size(){
    return size_fl;
}

template<typename T>
void c_forward_list<T>::push_back(T data){
    if(root==nullptr){
        root=new Node(data);
    }
    else{
        Node *current=root;
        while(current->p_next!=nullptr){
            current=current->p_next;
        }
        current->p_next=new Node(data);
    }
    size_fl++;
}

template<typename T>
void c_forward_list<T>::insert(int index, T data){ //insert after
    if(index!=-1 && index>=size_fl)
        throw std::out_of_range("list index out of range");
    Node* current=root;
    for(int i=0;i<index;i++){
        current=current->p_next;
    }
    if(index==-1){
        Node* temp=new Node(data, current);
        root=temp;
    }
    else{
        Node* temp=new Node(data, current->p_next);
        current->p_next=temp;
    }
    size_fl++;
}

template<typename T>
T c_forward_list<T>:: erase(size_t index){ //erase_after
    if(index>=size_fl-1)
        throw std::out_of_range("list index out of range");
    Node* current=root;
    for(int i=0;i<index;i++){
        current=current->p_next;
    }
    
    Node* temp=current->p_next;
    T delData=temp->data;
    current->p_next=temp->p_next;
    delete temp;
    size_fl--;
    return delData;
}

template<typename T>
typename c_forward_list<T>::iterator c_forward_list<T>::begin(){
    return iterator(root);
}

template<typename T>
typename c_forward_list<T>::iterator c_forward_list<T>::end(){
    return iterator(nullptr);
}

template<typename T>
T& c_forward_list<T>::operator[](const size_t index){
    if(index>=this->size_fl)
        throw std::invalid_argument("Index must be less than f_list's size");
    auto it=begin();
    for( int i=0;i<index;i++){
        ++it;
    }
    return *it;
}

template<typename T>
const T& c_forward_list<T>::operator[](const size_t index)const{
    if(index>=this->size_fl)
        throw std::invalid_argument("Index must be less than f_list's size");
    auto it=begin();
    for( int i=0;i<index;i++){
        ++it;
    }
    return *it;
}

template<typename T>
c_forward_list<T>::c_forward_list(const c_forward_list<T>& another_list){
    if(this->root!=nullptr)
        delete this->root;
    this->size_fl=another_list.size_fl;
    this->root=another_list.root;
    
}
template<typename T>
c_forward_list<T>::c_forward_list(c_forward_list<T>&& another_list) noexcept{
    if(this->root!=nullptr)
        delete this->root;
    this->size_fl=another_list.size_fl;
    this->root=another_list.root;
    another_list.size_fl = 0;
    another_list.root = nullptr;
}

template<typename T>
c_forward_list<T>& c_forward_list<T>:: operator=(const c_forward_list<T> & another_list){
    if(this->root!=nullptr)
        delete this->root;
    this->size_fl=another_list.size_fl;
    this->root=another_list.root;
    return *this;
}

#endif