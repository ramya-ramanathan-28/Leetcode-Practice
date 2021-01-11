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
        ListNode* initial = new ListNode(-1), *l1 = initial, *l2_initial = new ListNode(-1), *l2=l2_initial ;
        while(head!=NULL){
            if(head->val<x){
                l1->next = head; 
                l1 = l1->next;
            }
            else {
                l2->next = head;
                l2 = l2->next;
            }
            head = head->next;
            
        }
        l1->next = l2_initial->next;
        l2->next = NULL;
        return initial->next;
    }
};