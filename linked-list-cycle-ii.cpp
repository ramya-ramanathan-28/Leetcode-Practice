/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode * slow = head, *fast = head;
        bool isCycle = false;
        while(slow!=NULL && fast!=NULL){
            slow = slow->next;
            if(fast->next==NULL){
                return NULL;
            }
            fast = fast->next->next;
            if(slow == fast){
                isCycle = true;
                break;
            }   
        }
        
        if(isCycle){
            slow = head;
            while(slow!=fast){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
        return NULL;
    }
};