#include <iostream>
#include <queue>
#include "include/node.h"
#define max(a, b) (a < b) ? b : a

class Solution
{
public:
    // 反转链表
    Node *reverse(Node *head)
    {
        Node *pre = nullptr;
        Node *curr = head;
        Node *nxt = nullptr;
        while (curr != nullptr)
        {
            nxt = curr->next;
            curr->next = pre;
            pre = curr;
            curr = nxt;
        }
        return pre;
    }

    // 反转m到n的链表
    Node *reverse(Node *head, int m, int n)
    {
        Node *headPre = new Node(0, head);
        Node *h0 = headPre;

        for (int i = 1; i < m; i++)
            h0 = h0->next;

        Node *pre = nullptr;
        Node *curr = h0->next;
        Node *nxt = nullptr;

        for (int i = 0; i < n - m + 1; i++)
        {
            if (curr != nullptr)
            {
                nxt = curr->next;
                curr->next = pre;
                pre = curr;
                curr = nxt;
            }
        }
        h0->next->next = curr;
        h0->next = pre;
        return headPre->next;
    }
    // 删除中间节点
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
    // 奇偶链表,奇数位节点在前, 偶数位节点在后
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

    // 链表最大孪生和 node(i) + node(n-i+1) = max
    int pairSum(Node *head)
    {
        if (!head)
            return 0;
        Node *fast = head;
        Node *slow = head;
        // 1.快慢指针, 寻找链表中点
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        // 如果链表的节点数是奇数，slow指针将指向中间节点；如果节点数是偶数，slow指针将指向靠近链表中心的前一个节点。
        // 2.反转后半链表
        Node *curr = slow;
        Node *pre = nullptr;
        Node *nxt = nullptr;
        while (curr)
        {
            nxt = curr->next;
            curr->next = pre;
            pre = curr;
            curr = nxt;
        }
        // 3.计算孪生和
        int maxTwinSum = 0;
        while (head && pre)
        {
            maxTwinSum = max(maxTwinSum, head->val + pre->val);
            head = head->next;
            pre = pre->next;
        }
        return maxTwinSum;
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

    Node *mergeLists = ss.mergeTwoLists(node1, node6);
    printList(mergeLists);
    return 0;
}