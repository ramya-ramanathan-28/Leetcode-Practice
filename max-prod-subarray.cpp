class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProduct = 1; 
        int minProduct = 1;
        int maxSoFar = INT_MIN;
        for(int num: nums){
            int prod1 = maxProduct * num, prod2 = minProduct * num;
            maxProduct = max(max(prod1, prod2), num);
            minProduct = min(min(prod1, prod2), num);
            maxSoFar = max(maxSoFar, maxProduct); 
            
        }
        return maxSoFar;
    }
};