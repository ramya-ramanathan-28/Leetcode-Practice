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
    void verticalTraversalFunc(TreeNode* root, int x, map<int, vector<int>>&m){
        queue<pair<TreeNode*, int>> q; 
        q.push({root, 0});
        while(!q.empty()){
            set<pair<int, int> > tmp;  
             // If two nodes have the same position, then the value of the node that is reported first is the value that is smaller. So, making a set
            int size = q.size();
            for(int i=0; i<size; i++){
                pair<TreeNode*, int> val = q.front();
                q.pop();
                tmp.insert({val.first->val, val.second});
                if(val.first->left!=NULL){
                    q.push({val.first->left, val.second-1});
                }
                if(val.first->right!=NULL){
                    q.push({val.first->right, val.second+1});
                }
            }
            for(auto p : tmp) m[p.second].push_back(p.first);
        }
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<int>> m;
        vector<vector<int>> res;
        verticalTraversalFunc(root, 0, m);
        for(auto &val: m){
            res.push_back(val.second);
        }
        return res;
        
    }
};