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
    void reorderList(ListNode* head) {
        if(head==NULL){
            return;
        }
        ListNode* first= head, *second = head; 
        // Find middle
        while(second!=NULL && second->next!=NULL){
            first = first->next; 
            second = second->next->next; 
        }
        ListNode* prev = NULL, *curr = first, *next; 
        // Reverse list
        while(curr!=NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr; 
            curr = next;
        }
        first = head; 
        ListNode * following; 
        //Combine both lists. 
        while(first->next!=NULL && prev->next!=NULL){
            next = first->next; 
            first->next = prev; 
            following = prev->next; 
            prev -> next = next; 
            first = next; 
            prev = following; 
        }
        
        
        
    }
};
