#include <iostream>
#include <queue>
#include "include/node.h"

class Solution
{
public:
    // 删除中间节点,使用快慢指针
    Node *deleteMiddle(Node *head)
    {
        Node *prehead = new Node(0, head);
        Node *fast = prehead;
        Node *slow = prehead;
        if (fast == nullptr)
            return nullptr;
        ;
        while (fast && fast->next && fast->next->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
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
    Node *deleteMiddle = ss.deleteMiddle(node1);
    printList(deleteMiddle);
    return 0;
}
