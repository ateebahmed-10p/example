hile(lists.size() != 0)
        // {
        //     auto min_idx = lists.begin();
        //     for (auto i = lists.begin(); i != lists.end() ; i++)
        //     {
        //         if(*i)
        //         {
        //             if (*min_idx->val > *i->val)
        //                 min_idx = i; 
        //         }
        //     }
        //     // create a listnode to append it in the head
        //     ptr->next = new ListNode(*min_idx->val);
        //     ptr = ptr->next;
        //     *min_idx = *min_idx->next;
        //     if (min_idx == nullptr)
        //         lists.erase(min_idx);
        // }