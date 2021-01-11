class Solution {
public:
//     int findDuplicate(vector<int>& nums) {
//         int tortoise = nums[0];
//         int hare = nums[0]; 
//         do{
//             tortoise = nums[tortoise]; 
//             hare = nums[nums[hare]]; 
//         }while(tortoise!=hare);
        
//         tortoise = nums[0];
//         while(tortoise!=hare){
//             hare = nums[hare];
//             tortoise = nums[tortoise]; 
//         }
//         return hare; 
//     }
//         int findDuplicate(vector<int>& nums) {
//         set<int> NumsSet;
//         for(int i=0;i<nums.size();i++){
//             if(!NumsSet.count(nums[i]))
//                 NumsSet.insert(nums[i]);
//             else
//                 return nums[i];
//         }
//         return -1;
        
//     }
    int findDuplicate(vector<int>& nums){
        int l = 1, r = nums.size() - 1;
        while (l < r) {
            int m = l + (r - l) / 2, n = 0;
            cout<<m<<endl;
            for (int num : nums) {
                n += num <= m;
            }
            n <= m ? l = m + 1 : r = m;
        }
        return l;
    }
};