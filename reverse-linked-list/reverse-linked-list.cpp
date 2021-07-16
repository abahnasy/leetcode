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
    /*
    for each node:
        give me the reversed list next to me
        add me to the returned list
        pass the new head to the node before me
    */   
    ListNode* reverseList(ListNode* head) {
        // base case
        if(head == nullptr || head->next == nullptr)
            return head;
        // get the new head
        ListNode* temp = reverseList(head->next);
        // add me to the list
        head->next->next = head;
        // this step is important to make the last node refer to null !
        head->next = nullptr;
        return temp;
        
        
        
            
        
        
        
        
        // if (head == nullptr || head->next == nullptr)
        //     return head; //base case
        // ListNode* p = reverseList(head->next);
        // head->next->next =  head;
        // head->next = nullptr;
        // return p;
        
        
        
        //  ListNode* prev = nullptr;
        // ListNode* curr = head;
        // while(curr != nullptr) {
        //     ListNode* temp = curr->next;
        //     curr->next = prev;
        //     prev = curr;
        //     curr = temp;
        // }
        // return prev;
    }
};