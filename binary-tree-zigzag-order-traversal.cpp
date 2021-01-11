/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void checkAndPush(deque<TreeNode*>&q, TreeNode* root, bool right){
        if(root!=NULL){
            if(right){
                q.push_back(root); 
            }
            else {
                 q.push_front(root); 
            }
        }
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }
        deque<TreeNode*> q; 
        q.push_back(root);
        bool right = true;
        while(!q.empty()){
            int size = q.size();
            vector<int> mid_ans; 
            for(int i=0; i<size; i++){
                TreeNode* node;
                if(right){
                    node = q.front(); 
                    q.pop_front();
                }
                else{
                    node = q.back(); 
                    q.pop_back();
                }
                mid_ans.push_back(node->val);
                TreeNode * node1 = right? node->left: node->right;
                TreeNode * node2 = right? node->right: node->left;
                checkAndPush(q, node1, right); 
                checkAndPush(q, node2, right);   
            }
            ans.push_back(mid_ans); 
            right = !right; 
        }
        return ans;
    }
};