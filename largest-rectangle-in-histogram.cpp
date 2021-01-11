class Solution {
public:
//     int largestRectangleArea(vector<int>& heights) {
//         int n = heights.size();
//         if(n==0){
//             return 0;
//         }
//         vector<int> left(n);
//         vector<int> right(n);
//         int maxArea = 0, p;
//         right[n - 1] = n;
//         left[0] = -1;
//         for(int i=1; i<n; i++){
//             p = i-1;
//             while(p>=0 && heights[p]>=heights[i]){
//                 p = left[p];
//             }
//             left[i] = p;
//         }
        
//         for(int i=n-2; i>=0; i--){
//             p = i+1;
//             while(p<n && heights[p]>=heights[i]){
//                 p = right[p];
                
//             }
//             right[i] = p;
//         }
        
//         for(int i=0; i<n; i++){
//             maxArea = max(maxArea, heights[i] * (right[i] - left[i] -1));
//         }
//         return maxArea;
            
//     }
    int largestRectangleArea(vector<int>& heights){
       // Increasing stack: Explanation: https://www.youtube.com/watch?v=lktr76SxB2w
       stack<int> s; 
       int maxArea = 0; 
       // less than equal to because first time pushes in, then handles final area. 
       int i=0;
       while(i<heights.size()){
           if(s.empty()|| heights[i]>=heights[s.top()]){
               s.push(i++);
           }          
           else{
               int top = s.top();
               s.pop();
               maxArea = max(maxArea, heights[top]*(s.empty()?i:i-s.top()-1));
           }
       }
       while(!s.empty()){
           int top = s.top();
           s.pop();
           maxArea = max(maxArea, heights[top]*(s.empty()?i:i-s.top()-1));
       }
       return maxArea;
   } 
};