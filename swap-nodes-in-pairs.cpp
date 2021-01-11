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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode * dummy = new ListNode(-1); 
        dummy->next=head; 
        
        ListNode * prev = dummy, *curr=head;
        
        while(curr!=NULL && curr->next!=NULL){
            ListNode * nextNode = curr->next->next;
            prev->next = curr->next; 
            curr->next->next = curr; 
            prev = curr; 
            curr = nextNode; 
        }
        prev->next = curr; 

        return dummy->next; 
        
    }
};