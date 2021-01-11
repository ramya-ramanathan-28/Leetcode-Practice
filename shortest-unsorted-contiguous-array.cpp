class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int numsLength = nums.size();
        if(numsLength == 1)
            return 0;
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end()); 
        int first=0, second=numsLength-1;
        do{
            cout<<first<<second<<endl;
            if(sortedNums[first]==nums[first])
                first++;
            if(sortedNums[second]==nums[second])
                second--;
            
        }while((sortedNums[first]==nums[first] || sortedNums[second]==nums[second])  && first<second);
        if(second == first)
            return 0;
        return(second-first+1);
    }
};