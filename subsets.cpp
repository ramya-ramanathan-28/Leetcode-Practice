class Solution {
public:
    void getSubsets(vector<vector<int>> &result, vector<int> val, int currentIndex, vector<int>&nums){
        if(currentIndex == nums.size()){
            result.push_back(val);
            return;
        }
        getSubsets(result, val, currentIndex+1, nums);
        
        val.push_back(nums[currentIndex]);
        getSubsets(result, val, currentIndex+1, nums);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> val; 
        vector<vector<int>> result; 
        getSubsets(result, val, 0, nums);
        return result;
    }
};



