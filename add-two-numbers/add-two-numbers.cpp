/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c = 0;
        ListNode res = ListNode(0);
        ListNode* t = &res;
        while(l1 || l2 || c) {
            c = c + ((l1)?l1->val: 0) + ((l2)?l2->val:0);
            t->next = new ListNode(c%10);
            t = t->next;
            c = c/10;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        
        return res.next;
    }
};