class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int count = 0, newIndex=0, originalValue=0, replaceValue=nums[0];
        int numsLength = nums.size();
        for(int i=0;count<numsLength;i++){
        newIndex = i;  
        replaceValue=nums[i];
        do{
            newIndex =(newIndex+k)%numsLength;
            originalValue = nums[newIndex];
            nums[newIndex] = replaceValue;
            replaceValue = originalValue;
            count++;
        }while(newIndex!=i);
        }
    }
};