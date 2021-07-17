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
    ListNode* partition(ListNode* head, int x) {
        
        if(!head || !head->next)
            return head;

        
        ListNode dummy_before = ListNode(0, nullptr);
        ListNode dummy_after = ListNode(0, nullptr);
        ListNode* before = &dummy_before;
        ListNode* after = &dummy_after;
        
        ListNode* curr = head;
        while(curr) {
            
            if(curr->val < x) {
                
                before->next = curr;
                before = before->next;
                
            } else {
                after->next = curr;
                after = after->next;
            }
            
            curr = curr->next;
        }
        
        after->next = nullptr;
        // join
        before->next = dummy_after.next;
        return dummy_before.next;
        
        
    }
};



// class Solution {
// public:
//     ListNode* partition(ListNode* head, int x) {
//         if(!head || !head->next)
//             return head;
        
//         vector<ListNode*> before;
//         vector<ListNode*> after;
//         ListNode* curr = head;

//         while(curr) {
//             if(curr->val < x) {
//                 before.push_back(curr);
//                 // cout << "push before\n";
//             } else  {
//                 after.push_back(curr);
//                 // cout << "push after\n";
//             }
//              curr = curr->next;
//         }
//         // cout << " second stage \n";
//         if(before.size() != 0) {
//             // cout << "filling befroe \n";
//             head = before[0];
//             curr = head;
//             for(auto e: before) {
//                 if (e == head)
//                     continue; // skip the first assignment which happened before
//                 curr->next = e;
//                 curr = e;
//             }
//         }
//         else {
//             // cout << "if no before  \n";
//             head = after[0];
//             curr = head;
//             for(auto e: after) {
//                 if (e == head)
//                     continue; // skip the first assignment which happened before
//                 curr->next = e;
//                 curr = e;
//             }
//         }
        
//         for(auto e: after) {
//             // cout << "after value: " << e->val << "\n";
//             curr->next = e;
//             curr = e;
//         }
        
//         // derefrence the last node
//         curr->next = nullptr;
        
//         // debug print
//         // cout << "DEBUG PRINT \n";
//         curr = head;
//         while(curr) {
//             cout << curr->val <<", ";
//             curr = curr->next;
//         }
            
        
    

//         return head;
//     }
// };