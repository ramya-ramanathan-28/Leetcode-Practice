class Solution {
public:
    int rangeGreaterThan(vector<int> nums, int target){
        int n = nums.size();
        int left = 0, right = n-1, mid, result = n; 
         while(left<=right){
             mid = left + (right-left)/2;
             if(nums[mid]>=target){
                 result = mid; 
                 right = mid -1;
             }
             else {
                 left = mid+1;
             }
        }
        return(result);
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> output(2);
        output[0] = rangeGreaterThan(nums, target);
        output[1] = rangeGreaterThan(nums, target + 1) - 1;
        
        if(output[0] <= output[1]){
            return(output);
        }
        else {
            return {-1, -1};
        }
        return output;
    }
};