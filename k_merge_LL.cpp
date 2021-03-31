/*
 * Definition for singly-linked list.
*/
#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    // one by one comparision with time complexity of O(k*N)
    // where, k = number of linked lists , N = number of nodes in the final list
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        vector<ListNode*> Lists;
        Lists.reserve(lists.size());

        for (int i = 0 ; i != lists.size() ; i++)
        {
            if (lists[i])
                Lists.emplace_back(lists[i]);
        }

        if (Lists.size() == 0)
            return nullptr;

        ListNode head(0);
        ListNode* ptr = &head;
        // // start doing the comparision
        while(Lists.size() != 0)
        {
            auto min_idx = Lists.begin();
            for (auto i = Lists.begin(); i != Lists.end() ; i++)
            {
                if(*i)
                {
                    if ((*min_idx)->val > (*i)->val)
                        min_idx = i; 
                }
            }
            // create a listnode to append it in the head
            ptr->next = new ListNode((*min_idx)->val);
            ptr = ptr->next;
            *min_idx = (*min_idx)->next;
            if (*min_idx == nullptr)
                Lists.erase(min_idx);
        }

        return head.next;
    }
};

int main()
{
    vector<ListNode*> lists = {new ListNode(1) , new ListNode(2 , new ListNode(55)) , new ListNode(4)};
    Solution S;


    return 0;
}