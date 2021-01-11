/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSpecificNode(TreeNode* node, TreeNode* p, TreeNode* q, TreeNode ** ans) {
        if(node == NULL){
            return false; 
        }
        bool left = isSpecificNode(node->left, p,q, ans);
        bool right = isSpecificNode(node->right, p,q, ans);
        
        if(node == p || node ==q){
            if(left || right){
                *ans = node;
            }
            if(node == p && node == q){
                *ans = node;
            }
            return true;
        }
        if(left && right){
            *ans = node;
            return true;  
        }
        return left || right;
    }
    
    
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode * ans = NULL;
        isSpecificNode(root, p, q, &ans);
        return ans;
        
    }
};