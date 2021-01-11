class Solution {
public:
    int uniquePaths(int m, int n) {
        long ans = 1; 
        m--;
        n--;
        for(int i=m+1, j=1; i<=m+n; i++, j++){
            ans*=i;
            ans/=j;


        }
        return (int)ans;
        
    }
};
