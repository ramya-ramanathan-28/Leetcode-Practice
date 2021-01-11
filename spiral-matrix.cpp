class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& A) {
    vector<int> ans;
    if(A.size()==0||A[0].size()==0){
        return ans;
    }
    int count=0, dir=0, i_min=0, i_max=A.size()-1, j_min=0, j_max=A[0].size()-1;
    vector<char> direction{'r', 'd', 'l', 't'};
    while(i_min<=i_max && j_min<=j_max){
        switch(direction[dir%4]){
            case 'r':
            for(int j=j_min; j<=j_max; j++){
                ans.push_back(A[i_min][j]);
            }
            i_min++;
            break;
            case 'l':
            for(int j=j_max; j>=j_min; j--){
                ans.push_back(A[i_max][j]);
            }
            i_max--;
            break;
            case 'd':
            for(int i=i_min; i<=i_max; i++){
                ans.push_back(A[i][j_max]);
            }
            j_max--;
            break;
            case 't':
            for(int i=i_max; i>=i_min; i--){
                ans.push_back(A[i][j_min]);
            }
            j_min++;
            break;
        }
        dir++;
    }
    return ans;
    }
};

