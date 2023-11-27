#include <iostream>
#include <queue>
#include "include/node.h"

#define max(a,b) (a<b)?b:a

class Solution {
public:
    //链表最大孪生和 node(i) + node(n-i+1) = max
    int pairSum(Node* head)
    {
        if(!head) return 0;
        Node* fast = head;
        Node* slow = head;
        //1.快慢指针, 寻找链表中点
        while(fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        //如果链表的节点数是奇数，slow指针将指向中间节点；如果节点数是偶数，slow指针将指向靠近链表中心的前一个节点。
        //2.反转后半链表
        Node* curr = slow;
        Node* pre = nullptr;
        Node* nxt = nullptr;
        while(curr)
        {
            nxt = curr->next;
            curr->next = pre;
            pre = curr;
            curr =  nxt;
        }
        //3.计算孪生和
        int maxTwinSum = 0;
        while(head && pre)
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
    Node* node1 = new Node(1);
    Node* node2 = new Node(21);
    Node* node3 = new Node(11);
    Node* node4 = new Node(4);
    Node* node5 = new Node(9);

    // 连接节点形成链表
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    printList(node1);

    Solution ss;
    // Node* oddEvenList1 = ss.oddEvenList(node1);
    // printList(oddEvenList1);
    int maxValue = ss.pairSum(node1);
    std::cout<<maxValue<<std::endl;
    return 0;
}