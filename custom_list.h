#ifndef CUSTOM_LIST_H   
#define CUSTOM_LIST_H  

template<typename T>
class c_list{
private:
    class Node{
    public:
        Node *p_next;
        Node *p_prev;
        T data;
        Node(Node *p_prev=nullptr, Node *p_next=nullptr, T data=T()){
            this->p_prev=p_prev;
            this->p_next=p_next;
            this->data=data;
        }
    };
    Node* root;
    size_t size_;
public:
    class iterator{
    private:
        Node *current;
    public:
        iterator(Node *current=nullptr){
            this->current=current;
        }
        T& operator*(){
            return current->data;
        }
        bool operator!=(const iterator other) const{
            return current!=other.current;
        }
        iterator operator++(){
            current=current->p_next;   
            return *this;        
        }
        iterator operator--(){
            current=current->p_prev;
            return *this;
        }
    };
    c_list();
    c_list(const c_list<T>&another_list);
    c_list(c_list<T>&&another_list) noexcept;
    ~c_list();

    c_list<T>& operator=(const c_list<T>&);
    T& operator[](const size_t index);

    iterator begin();
    iterator end();

    size_t size();
    void push_back(T data);
    void push_front(T data);
    void pop_back(T data);
    void pop_front(T data);
    void insert(size_t index, T data);
    T erase(size_t index);
};
#endif

template <typename T>
c_list<T>::c_list()
{
    root=nullptr;
    size_=0;
}

template <typename T>
c_list<T>::c_list(const c_list<T> &another_list)
{
    this->root=another_list->root;
    this->size_=another_list->size_;
}

template <typename T>
c_list<T>::c_list(c_list<T> &&another_list) noexcept
{
    this->root=another_list->root;
    this->size_=another_list->size_;
    another_list->root=nullptr;
    another_list->size_=0;
}

template <typename T>
c_list<T>::~c_list()
{
    while(root!=nullptr){
        Node*temp=root;
        root=root->p_next;
        delete temp;
    }
}

template <typename T>
c_list<T> &c_list<T>::operator=(const c_list<T> &another_list)
{
    root=another_list->root;
    size_=another_list->size_;
    return *this;
}

template <typename T>
T &c_list<T>::operator[](const size_t index)
{
    if(index>=size_){
        throw std::out_of_range("index is larger than size");
    }
    Node *cur=root;
    for(int i=0;i<index;i++){
        cur=cur->p_next;
    }
    return cur->data;
}

template <typename T>
typename c_list<T>::iterator c_list<T>::begin()
{
    return iterator(root);
}

template <typename T>
typename c_list<T>:: iterator c_list<T>::end()
{
    return iterator(nullptr);
}

template <typename T>
size_t c_list<T>::size()
{
    return size_;
}

template <typename T>
void c_list<T>::push_back(T data)
{
     if(root==nullptr){
        root=new Node(nullptr, nullptr, data);
        size_++;
        return;
    }
    Node *cur=root;
    while(cur->p_next!=nullptr){
        cur=cur->p_next;
    }
    cur->p_next=new Node(cur, nullptr, data);
    size_++;
}

template <typename T>
void c_list<T>::push_front(T data)
{
    Node *temp=new Node(nullptr, root, data);
    root=temp;
    size_++;
}

template <typename T>
void c_list<T>::pop_back(T data)
{
    if(size_<1){
        throw std::out_of_range("list is empty");
    }
    Node *cur=root;
    while(cur->p_next!=nullptr){
        cur=cur->p_next;
    }
    delete cur;
    cur=nullptr;
    size_--;
}

template <typename T>
void c_list<T>::pop_front(T data)
{
    if(size_<1){
        throw std::out_of_range("list is empty");
    }
    Node *cur=root;
    root=root->p_next;
    delete cur;
    cur=nullptr;
    size_--;
}

template <typename T>
void c_list<T>::insert(size_t index, T data)
{
    if(root==nullptr){
        root=new Node(nullptr, nullptr, data);
        size_++;
        return;
    }
    Node *cur=root;
    for(int i=0;i<index-1;i++){
        cur=cur->p_next;
    }
    Node *temp=new Node(cur, cur->p_next, data);
    if(temp->p_next!=nullptr){
        cur->p_next->p_prev=temp;
    }
    cur->p_next=temp;
    size_++;
}

template <typename T>
T c_list<T>::erase(size_t index)
{
    T data;
    if(index>=size_){
        throw std::out_of_range("index is larger than lists size");
    }
    if(size_<1){
        throw std::out_of_range("list is empty");
    }
    Node *cur=root;
    if(index==0){
        data=root->data;
        root=root->p_next;
        delete cur;
        cur=nullptr;
        size_--;
        return data;
    }
    for(int i=0;i<index;i++){
        cur=cur->p_next;
    }
    data=cur->data;
    if(cur->p_prev!=nullptr){
        cur->p_prev->p_next=cur->p_next;
    }
    if(cur->p_next!=nullptr){
        cur->p_next->p_prev=cur->p_prev;
    }
    delete cur;
    cur=nullptr;
    size_--;
    return data;
}
