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
    
     void hasPathSum(TreeNode* root, int sum,vector<int> val, vector<vector<int>>&ans) {
        if(root==NULL){
            return;
        }
        sum = sum - root->val;
        val.push_back(root->val);
        if(root->left == NULL && root->right == NULL && sum==0){
            ans.push_back(val);
            return;
        }

        hasPathSum(root->left, sum, val, ans);
        hasPathSum(root->right, sum, val, ans);
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> val;
        vector<vector<int>> ans;
        hasPathSum(root, sum, val, ans);
        return ans;
        
    }
};