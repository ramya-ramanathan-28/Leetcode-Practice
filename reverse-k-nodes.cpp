class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* dummy = new ListNode(-1), *initial=dummy, *prev = NULL, *curr = head, *next, *endNode;
        dummy->next=head;
        int count = 0; 
        while(head!=NULL){
            count = count%k;
            if(count == k-1){
                for(int i=0; i<k; i++){
                    next = curr->next;
                    curr->next = prev;
                    prev = curr; 
                    curr =  next;
                    if(i==0){
                        endNode = prev;
                    }
                }
                initial->next = prev;
                initial = endNode;
                head = curr;
            }
            else{
                head = head->next;
            }
            count++;
        }
        if(count){
            initial->next = curr;
        }
        
        return dummy->next;
    }
};