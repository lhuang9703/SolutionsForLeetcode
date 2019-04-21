// Source : https://leetcode-cn.com/problems/remove-linked-list-elements/description/
// Number : 203
// Author : HL
// Date   : 2018-09-09
// Kill   : 98.33%

/********************************************************************************** 
Remove all elements from a linked list of integers that have value val.

Example:

Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5
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
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL)
            return NULL;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* p = dummy;
        while (p->next != NULL)
        {
            if (p->next->val == val)
                p->next = p->next->next;
            else
                p = p->next;
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *p = head;
        ListNode *q;
        while(p != NULL){
            if(p->val == val){
                q = p;
                p = p->next;
                head = p;
                delete q;
            }
            else
                break;
        }
        if(head == NULL)
            return NULL;
       for(p=head; p->next!=NULL;){
            q = p->next;
            if(q->val == val){
                p->next = q->next;
                delete q;
            }
            else
                p = p->next;
        }
        return head;
    }
};
