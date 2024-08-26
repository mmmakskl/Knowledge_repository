#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP
#include <iostream>

void test();

template<typename T>
class DictionaryList
{
public:

    DictionaryList() : size_(0), head_(nullptr) {};
    DictionaryList(DictionaryList<T>&& other);
    ~DictionaryList();

    void insert(T data);

    void increaseInsert(T data);

    void uniqueInsert(T data);

    void increaseUniqueInsert(T data);

    bool isEmpty() { return head_ == nullptr; }

    bool search(T data);

    void deleteWords(DictionaryList<T>& other);
    
    void remove(T data);

    T& operator[](const size_t index);

    void merge(DictionaryList<T>&& other);

    template<typename U>
    friend DictionaryList<U> getIntersection(DictionaryList<U>& dict1, DictionaryList<U>& dict2);

    template<typename U>
    friend std::ostream& operator << (std::ostream& out, const DictionaryList<U>& list);


private:
    
    void DeleteList();

    template<typename U>
    class Node
    {
    public:
        Node *pNext_;
        T data_;
        Node(T data = T(), Node *pNext = nullptr)
        {
            data_ = data;
            pNext_ = pNext;
        }
    };
    
    std::size_t size_;
    Node<T> *head_;

};

template<typename T>
void DictionaryList<T>::DeleteList()
{
    Node<T> *current = head_;
    Node<T> *next = nullptr;
    while (current)
    {
        next = current->pNext_;
        delete current;
        current = next;
    }
    head_ = nullptr;
}

template <typename T>
DictionaryList<T>::DictionaryList(DictionaryList<T>&& other) : head_(other.head_)
{
    other.head_ = nullptr;
}

template<typename T>
DictionaryList<T>::~DictionaryList()
{
    DeleteList();
}

template<class T> 
void DictionaryList<T>::increaseInsert( T data)
{
    Node<T> *newNode = new Node<T>(data);

    if (!head_ || data < head_->data_) 
    {
        newNode->pNext_ = head_;
        head_ = newNode;
        size_++;
        return;
    }

    Node<T> *current = head_;
    while (current->pNext_ && data > current->pNext_->data_) 
    {
        current = current->pNext_;
    }
    newNode->pNext_ = current->pNext_;
    current->pNext_ = newNode;

    size_++;
}

template <typename T>
void DictionaryList<T>::uniqueInsert(T data)
{
    if(!search(data))
        insert(data);
}

template <typename T>
void DictionaryList<T>::increaseUniqueInsert(T data)
{
    if(!search(data))
        increaseInsert(data);
}

template <typename T>
void DictionaryList<T>::insert(T data)
{
    if (!head_)
    {
        head_ = new Node<T>(data);
    }
    else
    {
        Node<T> *current = head_;
        while (current->pNext_)
        {
            current = current->pNext_;
        }
        current->pNext_ = new Node<T>(data);
    }

    size_++;
}

template <typename T>
bool DictionaryList<T>::search(T data)
{
    Node<T> *current = head_;
    while (current && current->data_ != data)
    {
        current = current->pNext_;
    }
    return current && current->data_ == data;
}

template <typename T> 
void DictionaryList<T>::deleteWords(DictionaryList<T> &other)
{
    Node<T> *current = other.head_;
    if(other.isEmpty()) 
    return;

    while (current)
    {
        remove(current->data_);
        current = current->pNext_;
    }
}

template <typename T>
void DictionaryList<T>::remove(T data)
{
    if(isEmpty()) return;
    if(head_->data_ == data)
    {
        Node<T> *temp = head_;
        head_ = head_->pNext_;
        delete temp;
        size_--;
    }
    else
    {
        Node<T>* current = head_;
        Node<T>* del = current->pNext_;
        while (del && del->data_ != data) {
            del = del->pNext_;
            current = current->pNext_;
        }
        if (!del) return;
        current->pNext_ = del->pNext_;
        delete del;
        size_--;
    }
    
}

template <typename T>
T &DictionaryList<T>::operator[](const size_t index)
{
    size_t count = 0;
    Node<T> *current = head_;
    while (current)
    {
        if (count == index)
        {
            return current->data_;
        }
        current = current->pNext_;
        count++;
    }
}

template <typename T>
void DictionaryList<T>::merge(DictionaryList<T> && other)
{
    if (!other.head_) 
        return;
    if (!head_) 
    {
        head_ = other.head_;
        size_ = other.size_;
        other.head_ = nullptr;
        other.size_ = 0;
        return;
    }
    Node<T> *current = other.head_;
    while (current) 
    {
        if (!search(current->data_)) 
        {
            Node<T>* newNode = new Node<T>(current->data_);
            Node<T>* prev = nullptr;
            Node<T>* present = head_;
            while (present && newNode->data_ > present->data_) 
            {
                prev = present;
                present = present->pNext_;
            }
            if (prev == nullptr) 
            {
                newNode->pNext_ = head_;
                head_ = newNode;
            } 
            else 
            {
                prev->pNext_ = newNode;
                newNode->pNext_ = present;
            }
            size_++;
        }
        Node<T>* toDelete = current;
        current = current->pNext_;
        delete toDelete;
    }

    other.head_ = nullptr;
    other.size_ = 0;
}

template<typename T> 
DictionaryList<T> getIntersection(DictionaryList<T> &dict1, DictionaryList<T> &dict2)
{
    DictionaryList<T> intersection;
    typename DictionaryList<T>::template Node<T>* current = dict1.head_;
    while ( current )
    {
        if(dict2.search(current->data_))
        {
            intersection.insert(current->data_);
        }
        current = current->pNext_;
    }
    return intersection;
}

template <typename T>
std::ostream& operator << (std::ostream& out, const DictionaryList<T>& list)
{
    typename DictionaryList<T>::template Node<T>* current = list.head_;
    if (!current)
    {
        out << "[ ]" << std::endl;
        return out;
    }
    out << "[";
    while (current)
    {
        if (!current->pNext_)
        {
        out << current->data_;
        current = current->pNext_;
        }
        else
        {
        out << current->data_ << ", ";
        current = current->pNext_;
        }
    }
    out << "]" << std::endl;
    return out;
}

#endif
