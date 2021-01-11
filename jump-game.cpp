class Solution {
public:
    bool canJump(vector<int>& nums) {
       int last_index = nums.size() -1;
        for(int i=last_index-1; i>=0;i--){
            if(last_index - i <= nums[i])
                last_index = i;
        }
        return !last_index;
    }
};