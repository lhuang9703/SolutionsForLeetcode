// Source : https://leetcode-cn.com/problems/linked-list-cycle/description/
// Number : 141
// Author : HL
// Date   : 2018-09-03
// Kill   : 98.85%，37.14%

/********************************************************************************** 
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
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
    bool hasCycle(ListNode *head) {
        if(head == NULL)
            return false;
        
        // 双指针解法
        // ListNode *p = head;
        // ListNode *q = p->next;
        // while(q != p){
        //     if(q == NULL || q->next == NULL)
        //         return false;
        //     p = p->next;
        //     q = q->next->next;
        // }
        // return true;
        
        // 哈希解法
        map<ListNode*,ListNode*> mp;
        ListNode *p = head;
        while(p != NULL){
            if(mp.find(p->next) != mp.end())
                return true;
            else{
                mp[p] = p->next;
                p = p->next;
            }
        }
        return false;
    }
};
