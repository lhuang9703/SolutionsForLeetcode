// Source : https://leetcode-cn.com/problems/swap-nodes-in-pairs/description/
// Number : 24
// Author : HL
// Date   : 2018-09-13
// Kill   : 97.36%

/********************************************************************************** 
Given a linked list, swap every two adjacent nodes and return its head.

Example:

Given 1->2->3->4, you should return the list as 2->1->4->3.
Note:

Your algorithm should use only constant extra space.
You may not modify the values in the list's nodes, only nodes itself may be changed.
**********************************************************************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode *p = head, *q = head->next, *r;
        while(1)
        {
            p->next = q->next;
            q->next = p;
            if(p != head)
                r->next = q;
            else
                head = q;
            r = p;
            p = p->next;
            if(p == NULL)
                break;
            q = p->next;
            if(q == NULL)
                break;
        }
        return head;
    }
};
