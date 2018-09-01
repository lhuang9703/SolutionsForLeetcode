// Source : https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/description/
// Number : 83
// Author : HL
// Date   : 2018-09-01
// Kill   : 100.00%

/********************************************************************************** 
Given a sorted linked list, delete all duplicates such that each element appear only once.

Example 1:

Input: 1->1->2
Output: 1->2
Example 2:

Input: 1->1->2->3->3
Output: 1->2->3
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL)
            return head;
        ListNode *p = head,*q = p->next;
        while(q != NULL){
            if(q->val == p->val){
                p->next = q->next;
                delete(q);
                q = p->next;
            }
            else{
                p = p->next;
                q = q->next;
            }
        }
        return head;
    }
};
