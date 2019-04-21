// Source : https://leetcode-cn.com/problems/reverse-linked-list-ii/description/
// Number : 92
// Author : HL
// Date   : 2018-09-13
// Kill   : 96.40%

/********************************************************************************** 
Reverse a linked list from position m to n. Do it in one-pass.

Note: 1 ≤ m ≤ n ≤ length of list.

Example:

Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == NULL)
            return NULL;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *p = dummy, *q, *r;
        for (int i = 1; i < m; i++)
        {
            p = p->next;
        }
        q = p->next;
        r = p->next->next;
        for (int i = 0; i < n - m; i++)
        {
            q->next = r->next;
            r->next = p->next;
            p->next = r;
            r = q->next;
        }
        return dummy->next;
    }
};


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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == NULL)
            return head;
        
        ListNode *p = head, *q = head, *r = head->next, *s;
        int step = 0;
        while (r != NULL) {
            if (step < m-1) {
                p = p->next;
                q = q->next;
                r = r->next;
            } else if (step == n-1) {
                break;
            } else {
                s = r->next;
                r->next = q;
                q = r;
                r = s;
            }
            step++;
        }
        
        s = head;
        if (s == p) {
            p->next = r;
            head = q;
        } else {
            while (s->next != p) {
                s = s->next;
            }
            s->next = q;
            p->next = r;
        }
        
        return head;
    }
};
