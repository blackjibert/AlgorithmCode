#include <iostream>
#include "include/node.h"

class Solution
{
public:
    // 合并两个有序链表
    Node *mergeTwoLists(Node *head1, Node *head2)
    {
        Node *pre = new Node(0);
        Node *curr = pre;
        while (head1 && head2)
        {
            if (head1->val < head2->val)
            {
                curr->next = head1;
                head1 = head1->next;
            }
            else
            {
                curr->next = head2;
                head2 = head2->next;
            }
            curr = curr->next;
        }
        if (head1)
            curr->next = head1;
        if (head2)
            curr->next = head2;
        return pre->next;
    }
};

int main()
{

    // 创建链表节点示例
    Node *node1 = new Node(1);
    Node *node2 = new Node(4);
    Node *node3 = new Node(7);
    Node *node4 = new Node(8);
    Node *node5 = new Node(10);

    // 连接节点形成链表
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    printList(node1);

    // 创建链表节点示例
    Node *node6 = new Node(2);
    Node *node7 = new Node(6);
    Node *node8 = new Node(9);
    Node *node9 = new Node(22);
    Node *node10 = new Node(23);

    // 连接节点形成链表
    node6->next = node7;
    node7->next = node8;
    node8->next = node9;
    node9->next = node10;
    printList(node6);

    Solution ss;
    // Node* oddEvenList1 = ss.oddEvenList(node1);
    // printList(oddEvenList1);
    Node *mergeLists = ss.mergeTwoLists(node1, node6);
    printList(mergeLists);
    return 0;
}