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
    TreeNode * constructTree( vector<int> & preorder, int &p, unordered_map<int, int>&m, int is, int ie){
        if(is>ie){
            return NULL;
        }
            
        TreeNode * root = new TreeNode(preorder[p++]);
        int i = m[root->val];
        root-> left = constructTree(preorder, p, m, is, i-1);
        root->right = constructTree(preorder, p, m, i+1, ie);
        return root;
        
        
    }
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int p = 0;
        unordered_map<int, int> m; 
        for(int i=0; i<inorder.size(); i++){
            m[inorder[i]] = i;
        }
        return constructTree(preorder, p, m, 0, inorder.size()-1);
    }
};