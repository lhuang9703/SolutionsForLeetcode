// Source : https://leetcode-cn.com/problems/reverse-linked-list/description/
// Number : 206
// Author : HL
// Date   : 2018-09-11
// Kill   : 98.93%, 2.74%

/********************************************************************************** 
Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
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
    ListNode* reverseList(ListNode* head) {
        // 递归解法
        // if(head == NULL)
        //     return NULL;
        // if(head->next == NULL)
        //     return head;
        // ListNode* p = reverseList(head->next);
        // ListNode* q = p;
        // head->next = NULL;
        // while(q->next != NULL)
        //     q = q->next;
        // q->next = head;
        // return p;
        
        // 迭代解法
        if(head == NULL)
            return NULL;
        if(head->next == NULL)
            return head;
        ListNode* p = head;
        ListNode* q = head->next;
        while(q!=NULL)
        {
            ListNode* r = q->next;
            q->next = p;
            p = q;
            q = r;
        }
        head->next = NULL;
        return p;
    }
};
