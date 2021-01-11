class Solution {
public:
    // Sort solution
//     int maxWidthRamp(vector<int>& A) {
//     vector<pair<int, int>> m;     
//     for(int i=0; i<A.size(); i++){
//         m.push_back({A[i], i});
//     }
//     sort(m.begin(), m.end()); 
//     int i=0, j=1, diff=0;
//     while(j<A.size()){
//         if(m[j].second> m[i].second){
//             diff = max(diff, m[j].second - m[i].second); 
//             j++;
//         }
//         else
//         {
//             i++;
//         }
//         if(i==j){j++;}
//     }
//         return diff;
//     }
    
    
    // BEST SOLUTION
    int maxWidthRamp(vector<int>& A) {
        stack<int> s; 
        for(int i=0; i<A.size(); i++){
            if(s.empty() || A[i]<A[s.top()]){
                s.push(i);
            }
        }
        int diff = 0;
        for(int i=A.size()-1; i>=0; i--){
            while(!s.empty() && A[i]>=A[s.top()]){
                diff = max(diff, i - s.top());
                // Popping because this is the max possible combination for current i
                // as j becomes less than current j
                s.pop();
            }
        }
        return diff;
    }

    // Binary search solution
//     int maxWidthRamp(vector<int>& A){
//         vector<int> s;
//         int res = 0, n = A.size();
//         for (int i = 0; i < n; ++i) {
//             if (s.size() == 0 || A[i] < A[s[s.size() - 1]]) {
//                 s.push_back(i);
//             } else {
//                 int left = 0, right = s.size() - 1, mid = 0;
//                 //Binary search the first smallest number before current number
//                 while (left < right) {
//                     mid = (left + right) / 2;
                    
//                     if (A[s[mid]] > A[i]) {
//                         left = mid + 1;
//                     } else {
//                         right = mid;
//                     }
//                 }
//                 res = max(res, i - s[left]);
//             }
//         }
//         return res;
//     }
};
