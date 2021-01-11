class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[i].size(); j++){
                if(board[i][j] == word[0] && dfs(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, string word, int i, int j, int count){
        if(count == word.size()){
            return true;
        }
        if(i<0||j<0||i>=board.size() || j>=board[i].size() || board[i][j]!=word[count]){
            return false;
        }
        char val = board[i][j];
        board[i][j] = ' ';
        bool found = dfs(board,word,i+1, j, count+1) || dfs(board,word,i-1, j, count+1) || dfs(board,word,i, j+1, count+1) || dfs(board,word,i, j-1, count+1);
        board[i][j] = val;
        return found;
    }
};