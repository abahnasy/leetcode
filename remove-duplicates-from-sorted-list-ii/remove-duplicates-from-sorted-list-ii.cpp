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
        ListNode* start = new ListNode();
        start->next = head;
        ListNode* curr = start;
        while(curr) {
            // cout << "check: " << curr->next->val << ", " << curr->next->next->val<< "\n";
            if(curr->next && curr->next->next && 
               (curr->next->val == curr->next->next->val)
              ) 
            {
                ListNode* dup = curr->next;
                while(dup->next && dup->val == dup->next->val)
                    dup = dup->next;
                curr->next = dup->next;
                // curr = dup->next;
                // cout << "if " << "\n";
                
                
                
            } else {
                curr = curr->next;
                // cout << "else " << "\n";
            }
            
            
        }
        
        return start->next;
    }
};