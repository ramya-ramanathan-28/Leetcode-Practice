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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* initial = new ListNode(-1), *prev = initial;
        initial->next = head;
        int count = 1;
        if(head->next==NULL || head==NULL || m==n){
            return head;
        }
        while(head!=NULL && count<m){
            prev = prev->next;
            count++;
        }
        ListNode *beforeReverse = prev;
        ListNode *lastReverse = prev->next;
        ListNode* curr = prev->next, *next;
        prev = NULL;
        while(count<=n && curr!=NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;    
        }
         
        if(count<=n){
            return prev;
        }
        else{
            beforeReverse->next = prev;
            lastReverse->next = curr;
        }
           
        return initial->next;
    }
};