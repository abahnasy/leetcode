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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 ==nullptr && l2 == nullptr) return nullptr;
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;
        ListNode* p1 = l1; ListNode* p2 = l2;
        // choose head
        ListNode* head = nullptr;
        if (p1->val < p2->val) {
            head = p1;
            p1 = p1->next;
        } else {
            head = p2;
            p2 = p2->next;
        }
        
        ListNode* curr = head;
        
        while(p1 !=nullptr && p2 != nullptr) {
            if(p1->val < p2->val) {
                curr->next = p1;
                p1 = p1->next;
            } else {
                curr->next = p2;
                p2 = p2->next;
            }
            curr = curr->next;
        }
        if(p1 != nullptr)
            curr->next = p1;
        if(p2 != nullptr)
            curr->next = p2;
        
        return head;
        
    }
};