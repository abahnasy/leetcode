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
        
        ListNode *p1 = head, *p2 = head;
        
        while (p2->next && p2->next->next) {
            p1 = p1->next;
            p2 = p2->next->next;
            if (p1 == p2) 
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