class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> m( n, vector<int>(n, INT_MAX)); 
        createMatrix(n, m, edges);
        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<i; j++){
                    int val1 = m[i][k];
                    int val2 = m[k][j];
                    int finalVal = INT_MAX; 
                    if(val1 <= INT_MAX - val2){
                        finalVal = val1+ val2;
                    }
                    m[j][i] = m[i][j] = min(m[i][j], finalVal);
                }
            }
        }
        int row = 0;
        int minVal = INT_MAX, val ; 
        for(int i=0; i<n; i++){
            val = 0;
            for(int j=0; j<n; j++){
                if(j<=i){
                    if(m[i][j]<=distanceThreshold)
                        val++;
                }
                else{
                    if(m[j][i]<=distanceThreshold)
                        val++;
                }
            }
            if(val<=minVal){
                minVal = val;
                row = i; 
            }
        }
        return row;
        
    }
    
    void createMatrix(int n, vector<vector<int>>& AM, vector<vector<int>>& edges){
        for(auto edge: edges){
            AM[edge[0]][edge[1]] = edge[2];
            AM[edge[1]][edge[0]] = edge[2];
        }
        for(int i=0; i<n; i++){
            AM[i][i] = 0; 
        }
        
    }
};