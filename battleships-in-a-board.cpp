class Solution {
private: 
public:
    int countBattleships(vector<vector<char>>& board) {
        int numBattleShips = 0;
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[i].size(); j++){
                if(board[i][j] == '.'){
                    continue;
                }
                if(i> 0 && board[i-1][j] == 'X'){
                    continue;
                }
                if(j> 0 && board[i][j-1] == 'X'){
                    continue;
                }
                numBattleShips++;
            }
        }
        return numBattleShips;
    }

};