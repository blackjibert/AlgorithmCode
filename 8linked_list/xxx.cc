#include <iostream>
#include "include/node.h"
#include <queue>
class Solution {
public:
    //反转从m到n的链表
    Node *reverse(Node *head, int m, int n)
    {   
        Node* headPre = new Node(0,head);
        Node* h0 = headPre;

        for(int i=1;i<m; i++) h0 = h0->next;

        Node *pre = nullptr;
        Node *curr = h0->next;
        Node *nxt = nullptr;
        
        for(int i=0; i<n-m+1; i++)
        {
            if(curr!=nullptr)
            {
                nxt = curr->next;
                curr->next = pre;
                pre = curr;
                curr = nxt; 
            }
        }
        h0->next->next = curr;
        h0->next =pre;
        return headPre->next;
    }
};

int main() {

   // 创建链表节点示例
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    Node* node5 = new Node(5);

    // 连接节点形成链表
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    printList(node1);

    Solution ss;
    Node* reversedHead = ss.reverse(node1, 2, 5);
    printList(reversedHead);
    return 0;
}
