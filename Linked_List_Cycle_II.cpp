# number : 142

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
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return nullptr;
        ListNode *slow_ptr, *quick_ptr;
        slow_ptr = quick_ptr = head;
        bool isCycle = false;
        while (quick_ptr != nullptr && quick_ptr->next != nullptr) {
            slow_ptr = slow_ptr->next;
            quick_ptr = quick_ptr->next->next;
            if (slow_ptr == quick_ptr) {
                isCycle = true;
                break;
            }
        }
        if (!isCycle)
            return nullptr;
        else {
            ListNode *p = head;
            while (p != slow_ptr) {
                p = p->next;
                slow_ptr = slow_ptr->next;
            }
            return p;
        }
    }
};
