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
    void getNode(TreeNode * root, TreeNode** prev,  vector<TreeNode*>& v){
        if(root==NULL){
            return;
        }
        getNode(root->left,prev, v);
         if(*prev!=NULL && (*prev)->val>root->val){
             if(v[0] == NULL){
                v[0] = *prev;
                v[1] = root;
             }
             else{
                v[1] = root;
             }

        }
        *prev=root;
        getNode(root->right,prev, v);
    }
    
    
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> v(2, NULL);
        TreeNode * prev = NULL;
        getNode(root,&prev, v);
        int temp = v[0]->val;
        v[0]->val = v[1]->val;
        v[1]->val = temp;
        
    }
    
};