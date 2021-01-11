class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        unordered_map<int, vector<int>> m;
        int maxKey = 0; 
        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<nums[i].size(); j++){
                    m[i+j].push_back(nums[i][j]);
                    maxKey = max(maxKey, i+j);
            }
        }
        vector<int> ans;
        for(int i=0; i<=maxKey; i++){
            //reverse begin and end
            for(auto j=m[i].rbegin(); j!=m[i].rend(); j++){
                ans.push_back(*j);
            }
        }
        return ans;
    }
};