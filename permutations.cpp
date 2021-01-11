class Solution {
public:
    void generatePermutations(vector<vector<int>>&result, vector<int>& combi, vector<int>& nums, vector<int>& visited, int numsSize){
        if(combi.size()==numsSize){
            result.push_back(combi); 
            return;
        }
        for(int i=0; i<numsSize; i++){
            if(!visited[i]){
                combi.push_back(nums[i]);
                visited[i] = 1; 
                generatePermutations(result, combi, nums, visited, numsSize);
                combi.pop_back();
                visited[i] = 0;
            }
        }
    }

    
    vector<vector<int>> permute(vector<int>& nums) {
        int numSize = nums.size();
        vector<vector<int>> result;
        if(numSize==0){
            return result; 
        }
        vector<int> combi; 
        vector<int> visited(numSize, 0); 
        generatePermutations(result, combi, nums, visited, numSize); 
        return result; 
    }
};
