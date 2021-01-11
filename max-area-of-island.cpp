class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxi = 0, area; 
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]){
                    area = recur(grid, i, j);
                    maxi = max(area, maxi);
                }

            }
        }
        return maxi;
    }
    
    int recur(vector<vector<int>>& grid, int i, int j){
        if(i<0 || j<0 ||i>=grid.size() || j>=grid[0].size() || grid[i][j]==0)
            return 0;
        grid[i][j] = 0;
        return 1+recur(grid, i, j-1) + recur(grid, i-1, j) + recur(grid, i+1, j) + recur(grid, i, j+1);
    }
};