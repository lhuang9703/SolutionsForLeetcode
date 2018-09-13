// Source : https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/description/
// Number : 82
// Author : HL
// Date   : 2018-09-13
// Kill   : 85.51%

/********************************************************************************** 
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

Example 1:

Input: 1->2->3->3->4->4->5
Output: 1->2->5
Example 2:

Input: 1->1->1->2->3
Output: 2->3
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
        if (head == NULL || head->next ==NULL)
            return head;
        
        set<int> duplicateNode;
        ListNode *p = head, *q = head->next;
        while (q != NULL) {
            if (p->val == q->val) {
                duplicateNode.insert(p->val);
                p->next = q->next;
                delete q;
                q = p->next;
            } else {
                p = q;
                q = q->next;
            }
        }
        
        p = head, q = head->next;
        while (q != NULL) {
            if (duplicateNode.find(q->val) != duplicateNode.end()) {
                p->next = q->next;
                delete q;
                q = p->next;
            } else {
                p = q;
                q = q->next;
            }
        }
        
        if (duplicateNode.find(head->val) != duplicateNode.end()) {
            q = head;
            head = head->next;
            delete q;
        }
        
        return head;
    }
};
