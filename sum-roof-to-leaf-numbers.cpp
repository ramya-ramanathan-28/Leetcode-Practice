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
    void sumNumbersFunc(TreeNode * node, int val, int &sum){
        if(node==NULL){
            return;
        }
        val = val*10+node->val;
        if(node->left==NULL && node->right==NULL){
            sum+=val;
        }
        sumNumbersFunc(node->left, val, sum);
        sumNumbersFunc(node->right, val, sum);
    }
    
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        sumNumbersFunc(root, 0, sum);
        return sum;
    }
};