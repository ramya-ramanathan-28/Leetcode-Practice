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
        if(head==NULL){
            return NULL; 
        }
        ListNode *pointer = head, *initial = new ListNode(-1), *prev= initial;
        initial->next = head; 
        int deletedVal = INT_MIN; 
        while(pointer!=NULL){
            if(deletedVal==pointer->val){
                prev->next = pointer->next; 
                pointer = prev->next;
            }
            else if(pointer->next==NULL){
                break;
            }
            else if(pointer->next->val == pointer->val){
                prev->next = pointer->next->next; 
                deletedVal = pointer->val;
                pointer = prev->next; 
            }
            else{
                prev = prev->next;
                pointer = pointer->next; 
            }
           
        }
        return initial->next; 
    }
};