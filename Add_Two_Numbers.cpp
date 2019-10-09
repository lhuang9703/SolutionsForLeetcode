# number : 2

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p = l1, *q = l2;
        ListNode *dummy = new ListNode(0);
        ListNode *curr = dummy;
        int flag = 0;
        while (p != nullptr || q != nullptr) {
            int a = (p != nullptr) ? p->val : 0;
            int b = (q != nullptr) ? q->val : 0;
            int tmp = a + b + flag;
            curr->next = new ListNode(tmp % 10);
            flag = (tmp >= 10) ? 1 : 0;
            curr = curr->next;
            if (p != nullptr)   p = p->next;
            if (q != nullptr)   q = q->next;
        }
        if (flag == 1) {
            curr->next = new ListNode(1);
        }
        return dummy->next;
    }
};
