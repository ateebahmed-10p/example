#include <iostream>
using namespace std;

class list_of_ints
{
    // node structure definition
    struct node 
    {
        int data;
        node *next;
    };

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


// very inefficient, doubling each element should be an O(n) task, here it takes O(n^2). list_of_ints::at() is O(n).
template <typename Container>
void double_each_element(Container& arr)
{
    for (int i = 0; i < arr.size() ; i++)
        arr.at(i) *= 2; 
}

int main()
{
    list_of_ints arr;
    for (int i = 0 ; i < 10 ; i++)
    {
        arr.push_back(i+349892);
    }

    double_each_element(arr);

    for (int i = 0 ; i < 10 ; i++)
    {
        cout << arr.at(i) << endl;
    }

    return 0;
}