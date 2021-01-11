class Solution {
public:
   int calculateMaxArea(vector<int>& heights){
       // Increasing stack: Explanation: https://www.youtube.com/watch?v=lktr76SxB2w
       // Geeks for geeks article: https://www.geeksforgeeks.org/largest-rectangle-under-histogram/
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
    
   int maximalRectangle(vector<vector<char> > &matrix) {
       int n = matrix.size();
       if(!n){
           return 0; 
       }
       int maxArea = 0;
       int m = matrix[0].size();
       vector<int> heights(m);
       for(int i=0; i<n; i++){
           for(int j=0; j<m; j++){
               if(matrix[i][j] == '1'){
                   heights[j]++;
               }
               else{
                   heights[j] = 0;
               }
           }
           maxArea = max(maxArea, calculateMaxArea(heights)); 
       }
       return maxArea;
    }
};
    