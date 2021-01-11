class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> output(n);
        output[0] = 1; 
        int R = 1;
        for(int i=1; i<n; i++){
            output[i] = output[i-1] * nums[i-1];       
        }
        for(int i=n-2; i>=0; i--){
            R = R * nums[i+1];
            output[i] = output[i] * R;
        }
        return output;
    }
    
};