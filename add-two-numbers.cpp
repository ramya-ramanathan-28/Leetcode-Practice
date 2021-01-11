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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0, sum=0;
        ListNode * initial = new ListNode(-1), *l3=initial; 
        while(l1!=NULL && l2!=NULL){
            sum = l1->val + l2->val + carry;
            l3->next = new ListNode(sum%10);
            carry = sum/10;
            l3=l3->next;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1!=NULL){
            sum = l1->val + carry;
            l3->next = new ListNode(sum%10);
            carry = sum/10;
            l3=l3->next;
            l1=l1->next;
        }
        while(l2!=NULL){
            sum = l2->val + carry;
            l3->next = new ListNode(sum%10);
            carry = sum/10;
            l3=l3->next;
            l2=l2->next;
        }
        if(carry){
            l3->next = new ListNode(carry); 
        }
        return initial->next;
        
    }
};