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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next)
            return head;
        
        ListNode odd_head(0, nullptr);
        ListNode even_head(0, nullptr);
        ListNode* odd_ptr = &odd_head;
        ListNode* even_ptr = &even_head;
        
        int c = 1;
        while(head) {
            if(c%2 == 1) {
                odd_ptr->next = head;
                odd_ptr = odd_ptr->next;
            } else {
                even_ptr->next = head;
                even_ptr = even_ptr->next;
            }
            head = head->next;
            ++c;
        }
        
        //join
        odd_ptr->next = even_head.next;
        
        //dereference the last node
        even_ptr->next = nullptr;
        
        return odd_head.next;
        
    }
};