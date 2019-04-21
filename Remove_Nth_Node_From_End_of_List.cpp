// Source : https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/description/
// Number : 19
// Author : HL
// Date   : 2018-09-12
// Kill   : 80.65%

/********************************************************************************** 
Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL)
            return NULL;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode *p = dummy, *q = dummy;
        for (int i = 0; i < n; i++)
            p = p->next;
        while (p->next != NULL)
        {
            p = p->next;
            q = q->next;
        }
        q->next = q->next->next;
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p=head,*r;
        ListNode* q=head;
        if(n == 1)
        {
            if(p->next == NULL)
                return NULL;
            while(p->next != NULL)
            {
                r = p;
                p = p->next;
            }
            r->next = NULL;
            delete p;
            return head;
        }
        for(int i=n-1; i>0; i--)
            q = q->next;
        if(q->next == NULL)
        {
            head = p->next;
            delete p;
            return head;
        }
        while(q->next != NULL)
        {
            r = p;
            p = p->next;
            q = q->next;
        }
        r->next = p->next;
        delete p;
        return head;
    }
};
