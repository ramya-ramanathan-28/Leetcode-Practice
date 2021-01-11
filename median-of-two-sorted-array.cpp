class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int x= nums1.size();
        int y = nums2.size();
        if(y<x){
            // Length of first array is shorter to do binary search. 
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int low = 0, high = x, partitionX, partitionY, leftX, leftY, rightX, rightY;
        while(low <= high){
            partitionX = (low + high)/2; 
            // Total number of elements on each side of partition = (x+y+1)/2
            partitionY = (x+y+1)/2 - partitionX;
            
            // If partition is such that there are no elements on left/right side of partition, set max/min values
            leftX = partitionX==0 ? INT_MIN: nums1[partitionX-1];
            rightX= partitionX==x? INT_MAX: nums1[partitionX];
            leftY = partitionY==0 ? INT_MIN: nums2[partitionY-1];
            rightY= partitionY==y? INT_MAX: nums2[partitionY];

            if(leftX<=rightY && leftY<=rightX){
                if((x+y)%2==0){
                    
                   return ((double)max(leftX, leftY) + min(rightX, rightY))/2;
                }
                else{
                    return max(leftX, leftY); 
                }
                
            }
            else if(leftX>rightY){
                high = partitionX - 1; 
            }
            else{
                low = partitionX + 1;
            }
            
        }
        return -1; 
    }
};