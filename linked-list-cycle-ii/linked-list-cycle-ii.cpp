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
    ListNode *cycle(ListNode *head) {
        if(!head || !head->next)
            return nullptr;
        ListNode* f = head;
        ListNode* s = head;
        while(f->next && f->next->next) {
            f = f->next->next;
            s = s->next;
            if(f == s)
                return s;
        }
        return nullptr;
    
    }
    ListNode *detectCycle(ListNode *head) {
        
        ListNode* d = cycle(head);
        
        if(!d) {
            return nullptr;
        }
        
        ListNode* temp = head;
        while(temp != d) {
            d = d->next;
            temp = temp->next;
        }
        return temp;
        
        
        
    }
};







// class Solution {
// public:
//     unordered_map<ListNode*, bool> m;
    
//     ListNode *detectCycle(ListNode *head) {
        
//         if(!head) {
//             return nullptr;
//         }
//         ListNode* curr = head;
//         while(curr) {
//             if(m.find(curr) != m.end())
//                 return curr;
//             else
//                 m[curr] = true;
//             curr = curr->next;
//         }
        
//         return nullptr;
        
        
//     }
// };