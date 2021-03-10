#include <iostream>
using namespace std;

// node structure definition
struct node 
{
    int data;
    node *next;
};


class list_of_ints
{
    node *head_ = nullptr;
    node *tail_ = nullptr;
    int size_ = 0;

    public:
        int size(){ return size_; }
        int& at(int i)
        {
            node *p = head_;
            for (int j = 0 ; j < i ; j++)
                p = p->next;
            return p->data;
        }
        void push_back(int value)
        {
            node *new_tail = new node{value , nullptr};
            if (tail_)
            {
                tail_->next = new_tail;
            } else {
                head_ = new_tail;
            }
            tail_ = new_tail;
            size_ += 1;
        }
        ~list_of_ints()
        {
            for (node *next , *p = head_ ; p != nullptr ; p = next)
            {
                next = p->next;
                delete p;
            }
        }
};

template <typename Container>
void double_each_element(Container& arr)
{
    for (int i = 0; i < arr.size() ; i++)
        arr.at(i) *= 2; 
}

// very inefficient, doubling each element should be an O(n) task, here it takes O(n^2). list_of_ints::at() is O(n).
// to get rid of ::at() member method, we introduce a iterator which basically provides a pointer like interface like dereferencing (*) and arithmetic.
class list_of_ints_iterator
{
    node* ptr_;
    friend class list_of_ints_modified;
    explicit list_of_ints_iterator(node *p) : ptr_(p) {}
    public :
        int& operator*() const {return ptr_->data;}
        list_of_ints_iterator& operator++(){ ptr_ = ptr_->next; return *this;}
        bool operator==(const list_of_ints_iterator& rhs) const { return ptr_==rhs.ptr_;} 
        bool operator!=(const list_of_ints_iterator& rhs) const { return ptr_!=rhs.ptr_; }
};
// now we dont need to implement list_of_ints::at()
class list_of_ints_modified
{
    node *head_ = nullptr;
    node *tail_ = nullptr;
    int size_ = 0;

    public: 
        using iterator = list_of_ints_iterator;
        iterator begin() { return iterator(head_);}
        iterator end() { return iterator(nullptr);}

        int size(){ return size_; }
        void push_back(int value)
        {
            node *new_tail = new node{value , nullptr};
            if (tail_)
            {
                tail_->next = new_tail;
            } else {
                head_ = new_tail;
            }
            tail_ = new_tail;
            size_ += 1;
        }
        ~list_of_ints_modified()
        {
            for (node *next , *p = head_ ; p != nullptr ; p = next)
            {
                next = p->next;
                delete p;
            }
        }
};

template <typename Container>
void double_each_element_modified(Container& arr)
{
    // what is the type of auto here!!
    for ( auto it = arr.begin() ; it != arr.end(); ++it)
        *it *= 2;
} 


int main()
{
    list_of_ints_modified arr;
    for (int i = 0 ;  i < 10 ; i++)
    {
        arr.push_back(i);
    }

    double_each_element_modified(arr);
    
    for (auto it = arr.begin(); it != arr.end(); ++it)
        cout << *it << endl;
    
    
    
    return 0;
}