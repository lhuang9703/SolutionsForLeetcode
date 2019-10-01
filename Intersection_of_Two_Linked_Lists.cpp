# number : 160

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr)
            return nullptr;
        ListNode *pA = headA, *pB = headB;
        int countA = 1, countB = 1;
        while (pA->next != nullptr) {
            countA++;
            pA = pA->next;
        }
        while (pB->next != nullptr) {
            countB++;
            pB = pB->next;
        }
        if (pB != pA)
            return nullptr;
        
        ListNode *p, *q;
        if (countB > countA) {
            p = headB;
            q = headA;
        }
        else {
            p = headA;
            q = headB;
        }
        for (int i = 0; i < abs(countA - countB); i++)
            p = p->next;
        while (p != q) {
            p = p->next;
            q = q->next;
        }
        return p;
    }
};
