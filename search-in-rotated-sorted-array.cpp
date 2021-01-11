class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0, r=nums.size()-1, mid, start;
        // l<r because we want l to contain the starting element and not go beyond
        while(l<r){
            mid = l + (r-l)/2;
            // If mid is greater than r, something is incorrect
            // For example, [4, 5, 6, 7, 0, 1, 2] 7>2
            if(nums[mid]>nums[r]){
                l=mid+1;
            }
            else{
                // Not mid -1 to account for 
                // [5,6,7,0, 1,2,3] -> 0 should be included in left half
                r=mid;
            }
        }
        start = l;
        r=nums.size()-1;
        l=0;
        // Set boundaries based on pivot element (pivot - right)
        if(target>=nums[start] && target<=nums[r]){
            l = start;
        }
        else{
            // l to pivot
            r = start-1;
        }
        
        // Binary search normally
        while(l<=r){
            mid = l + (r-l)/2;
            if(target == nums[mid]){
                return mid;
            }
            else if(nums[mid]<target){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return -1;
    }
};
     
     
     
