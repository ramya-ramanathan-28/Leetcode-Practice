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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s; 
        vector<int> res; 
        TreeNode * curr = root;
        while(curr!=NULL || !s.empty()){
            while(curr!=NULL){
                s.push(curr); 
                curr = curr -> left;
            }
            TreeNode* val = s.top();
            s.pop();
            res.push_back(val->val); 
            curr = val->right; 
        }
     return res;
    }
};