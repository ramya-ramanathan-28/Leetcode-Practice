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
    int kthSmallest(TreeNode* root, int k) {
        int ans; 
        getNode(root, k, ans); 
        return ans;
            
    }
    
    void getNode(TreeNode* root, int& k, int& ans){
        if(root == NULL || k<0){
            return;
        }
        getNode(root->left, k, ans);
        k = k-1; 
        if(k==0){
            ans = root->val;
        }
        getNode(root->right, k, ans);   
        
    }
    
    
};