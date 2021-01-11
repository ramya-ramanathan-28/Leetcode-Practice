class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int result = INT_MAX; 
        int sum = 0, left = 0;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            while(sum>=s) {
                result = min(result, i+1-left);
                sum-=nums[left++];
                cout<<sum<<endl;
            }
        }
        return (result==INT_MAX? 0 : result);
    }
};