#include <iostream>
#include <vector>
#include "include/node.h"
class Solution {
public:
    Node* mergeTwoLists(Node* a, Node* b)
    {
        if((!a)||(!b)) return a?a:b;
        Node head; //head作为新链表的头指针，其中val为空
        Node* tail = &head;
        Node* aPtr = a;
        Node* bPtr = b;
        while(aPtr && bPtr)
        {
            if(aPtr->val < bPtr->val)
            {
                tail->next = aPtr;
                aPtr = aPtr->next;
            }
            else
            {
                tail->next = bPtr;
                bPtr = bPtr->next;
            }
            tail = tail->next;
        }
        tail->next = (aPtr?aPtr:bPtr);
        return head.next;
    }
    Node* mergeKLists(std::vector<Node*>& lists) 
    {
        Node* ans=nullptr;
        for(size_t i=0; i<lists.size();i++)
        {
            ans = mergeTwoLists(ans, lists[i]);
        }
        return ans;
    }
};

int main()
{   
    return 0;
}