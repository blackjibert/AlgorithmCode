#include <iostream>
#include <queue>
#include "include/node.h"
class Solution
{
public:
    // 奇偶链表
    Node *oddEvenList(Node *head)
    {
        if (!head || !head->next)
            return head;
        Node *odd = head;
        Node *even = head->next;
        Node *evenHead = even;
        while (even && even->next)
        {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};

int main()
{

    // 创建链表节点示例
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);
    Node *node5 = new Node(5);

    // 连接节点形成链表
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    printList(node1);

    Solution ss;
    Node *oddEvenList1 = ss.oddEvenList(node1);
    printList(oddEvenList1);
    return 0;
}