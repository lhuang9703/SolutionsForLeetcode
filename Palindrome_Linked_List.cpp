# number : 234

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
    bool isPalindrome(ListNode* head) {
        if (!head || !(head->next)) {
            return true;
        }
        ListNode *slow = head, *fast = head;
        ListNode *pre = nullptr, *temp;
        while (fast != nullptr && fast->next != nullptr) {
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
            temp->next = pre;
            pre = temp;
        }
        if (fast)  slow = slow->next;
        while (temp && slow) {
            if (temp->val != slow->val)
                return false;
            temp = temp->next;
            slow = slow->next;
        }
        return true;
    }
};
