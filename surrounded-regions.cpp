class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.size() == 0){
            return;
        }
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[i].size(); j++){
                if(i==0 || j==0 || i==board.size()-1 || j==board[i].size()-1 && (board[i][j] == 'O'))
                    processElement(board, i, j, visited);
            }
        }
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[i].size(); j++){
               if(board[i][j] == 'O'){
                   board[i][j] = 'X';
               }
            }
        }
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[i].size(); j++){
               if(board[i][j] == '#'){
                   board[i][j] = 'O';
               }
            }
        }
    }
    
    void processElement(vector<vector<char>>&board, int i, int j, vector<vector<bool>> &visited){
        if(i<0 || j<0 || i>=board.size() ||j>=board[i].size() || board[i][j] == 'X' || visited[i][j] ){
            return;
        }
        board[i][j] = '#';
        visited[i][j] = true;
        processElement(board, i+1, j, visited);
        processElement(board, i, j+1, visited);
        processElement(board, i-1, j, visited);
        processElement(board, i, j-1, visited);
    }
};