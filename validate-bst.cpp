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
    bool isValidBST(TreeNode* root) {
        return isBST(root, 0, 0, false, false); 
    }
    
    bool isBST(TreeNode* root, int max, int min, bool set_max, bool set_min){
        if(root == NULL){
            return true;
        }
        if(set_max && root->val>=max){
            return false;
        }
        if(set_min && root->val<=min){
            return false;
        }
        return isBST(root->left, root->val, min, true, set_min) && isBST(root->right, max, root->val, set_max, true);
    }
};