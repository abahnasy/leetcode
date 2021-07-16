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
        if (!head) 
            return false;
        
        ListNode *slow = head, *fast = head;
        
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) 
                return true;
        }
        
        return false;
    }
};






// class Solution {
// public:
//     unordered_map<ListNode*, bool> m;
//     bool hasCycle(ListNode *head) {
        
//         if (head == nullptr || head->next == nullptr)
//             return false;
//         ListNode* curr = head;
//         while(curr != nullptr) {
//             if(m.find(curr) != m.end()) {
//                 return true;
//             } else {
//                 m[curr] = true;
//             }
//             curr = curr->next;
//         }
        
//         return false;
        
        
    
//     }
// };