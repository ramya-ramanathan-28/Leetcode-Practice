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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        
        vector<int> traversal;
        TreeNode* curr = root;
        while(curr!=NULL || !s.empty()){
            while(curr!=NULL){
                traversal.insert(traversal.begin(),curr->val); //insert from front
                s.push(curr); // Same data structure and same push
                curr = curr->right; // reverse
            }
            TreeNode * top = s.top();
            s.pop();
            curr = top->left; //reverse
            
        }
        return traversal;
    }
};