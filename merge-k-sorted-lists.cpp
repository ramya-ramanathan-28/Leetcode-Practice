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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0){
            return NULL;
        }
        priority_queue<int, vector<int>, greater<int>> pq; 
        for(ListNode* head: lists){
            while(head!=NULL){
                pq.push(head->val);
                head = head->next;
            }
        }
        ListNode* returnHead =NULL;
        if(!pq.empty()){
            returnHead = new ListNode(pq.top());
            pq.pop();
        }
        ListNode* head = returnHead;
        while(!pq.empty()){
            head->next = new ListNode(pq.top());
            pq.pop();
            head=head->next;
            
        };
        return returnHead;
    }
};