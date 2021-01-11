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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL){
            return NULL;
        }
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* runner = dummy, *walker = dummy;
        int counter = 0;
        while(runner->next!=NULL){
            counter++;
            runner = runner -> next;
            if(counter>=n+1){
                walker = walker -> next;
            }
        }
        walker->next = walker->next->next;
        return dummy->next;
    }
};  
