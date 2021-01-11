class Solution {
public:
        bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int num: nums){
            sum+= num;
        }
        if(sum%2!=0){
            return false;
        }
        sum = sum/2;
        int n = nums.size();
        vector<bool> memo(sum+1, false);
        memo[0] = true;
        for(int i=1; i<=n; i++){
            for(int j=sum;j>=0; j--){
                cout<<j<<" "<<nums[i-1]<<" "<<j-nums[i-1]<<endl;
                if(j>=nums[i-1]){
                    memo[j] = memo[j] || memo[j-nums[i-1]];
                }
                
            }
            for(int j=0;j<=sum; j++){
                cout<<memo[j];
            }
            cout<<endl;
            
        }
        return memo[sum];
    }
//     bool canPartition(vector<int>& nums) {
//         int sum = 0;
//         for(int num: nums){
//             sum+= num;
//         }
//         if(sum%2!=0){
//             return false;
//         }
//         map<string, bool> m;
//         return findPartition(nums, 0, sum, 0, m);
//     }
    
//     bool findPartition(vector<int> &nums,i nt total, int index, map<string, bool> memo ){
//         if(index==nums.size() || sum> total/2){
//             return false;
//         }
//         if(sum==total/2){
//             return true;
//         }
//         string val = to_string(index)+to_string(sum);
        
//         if(memo.find(val)!=memo.end()){
//             return memo[val];
//         }
//         memo[val] = findPartition(nums, sum+nums[index], total, index+1, memo) || findPartition(nums, sum, total, index+1, memo);
//         return memo[val];
//     }
};