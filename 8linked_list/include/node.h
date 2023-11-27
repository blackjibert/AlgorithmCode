#ifndef NODE_H
#define NODE_H
#include <iostream>
// 链表节点结构体
struct Node
{
    int val;    // 节点的值
    Node *next; // 指向下一个节点的指针
    // 构造函数
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node *next1) : val(x), next(next1) {}
};

// 输出链表的值
void printList(Node *head)
{
    Node *current = head;
    while (current != nullptr)
    {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

#endif // LISTNODE_H