class Solution {
public:
//     int recursion(vector<int>&nums, vector<vector<int>>& memo, int prev, int cur){
//         if(cur==nums.size()){
//             return 0; 
//         }
//         if(prev!=-1 && memo[prev+1][cur]!=-1){
//             return memo[prev+1][cur];
//         }
//         int taken = 0; 
//         if(prev==-1 || nums[cur]>nums[prev]){
//             taken = 1 + recursion(nums, memo, cur, cur+1); 
//         }
//         int nottaken = recursion(nums, memo, prev, cur+1);
//         memo[prev+1][cur] = max(taken, nottaken); 
//         return memo[prev+1][cur]; 
        
//     }
    
    
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         vector<vector<int>> memo(n, vector<int>(n, -1));
//         return recursion(nums, memo, -1, 0);
//     }
    
    int lengthOfLIS(vector<int>& numnums) {
       vector<int> DP;
       
       int globalMaxi = 0;
       for(int i = 0; i < numnums.size(); ++i) {
           int maxi = 0;
           for(int j = 0; j < i; ++j) {
               if(numnums[i] > numnums[j]) {
                   maxi = max(maxi, DP[j]);
               }
           }
           DP.emplace_back(maxi + 1);
           globalMaxi = max(globalMaxi, maxi + 1);
       }        
       return globalMaxi;
   }
};