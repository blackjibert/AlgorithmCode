#include "include/node.h"

class Solution
{
public:
    // 反转链表
    Node *reverse(Node *head)
    {
        Node *pre = nullptr;
        Node *curr = head;
        Node *nxt = nullptr;
        while (curr)
        {
            nxt = curr->next;
            curr->next = pre;
            pre = curr;
            curr = nxt;
        }
        return pre;
    }
};

int main()
{

    // 创建链表节点示例
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);

    // 连接节点形成链表
    node1->next = node2;
    node2->next = node3;

    Solution ss;
    Node *reversedHead = ss.reverse(node1);
    // 调用输出函数，输出反转之后的值
    printList(reversedHead);
    return 0;
}
