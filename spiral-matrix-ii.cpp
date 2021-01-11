class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> A(n, vector<int>(n, 0));
        vector<char> direction{'r', 'd', 'l', 't'};
        int dir=0, i_min=0, i_max=n-1, j_min=0, j_max=n-1;
        int count = 1;
        while(i_min<=i_max && j_min<=j_max){
            switch(direction[dir%4]){
            case 'r':
            for(int j=j_min; j<=j_max; j++){
                A[i_min][j] = count++;
            }
            i_min++;
            break;
            case 'l':
            for(int j=j_max; j>=j_min; j--){
                A[i_max][j] = count++;
            }
            i_max--;
            break;
            case 'd':
            for(int i=i_min; i<=i_max; i++){
                A[i][j_max] = count++;
            }
            j_max--;
            break;
            case 't':
            for(int i=i_max; i>=i_min; i--){
                A[i][j_min] = count++;
            }
            j_min++;
            break;
        }
        dir++;
        }
        return A;
    }
};