class Solution {
public:
    int findMin(vector<int>& nums) {
      int l=0, r=nums.size()-1, mid;
      bool isLeftModified = false;
      // l<r because we want l to contain the starting element and not go beyond
      while(l<r){
          isLeftModified = false;
          mid = l + (r-l)/2;
          cout<<l<<endl;
          // If mid is greater than r, something is weird
          // For example, [4, 5, 6, 7, 0, 1, 2] 7>2
          if(nums[mid]>nums[r]){
              l=mid+1;
          }
          else if(nums[mid] == nums[r]){
            // Keep moving r till the mid and r are different
            r--;
          }
          else{
              // Not mid -1 to account for
              // [5,6,7,0, 1,2,3] -> 0 should be included in left half
              r=mid;
          }
      }
      return nums[l];
    }
};