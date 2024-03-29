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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return nullptr;
        ListNode* curr = head;
        while(curr) {
            if(curr->next && curr->next->val == curr->val) {
                curr->next = curr->next->next;
            } else {
                curr = curr->next;        
            }
        
        }
        
        return head;
        
        
    }
};