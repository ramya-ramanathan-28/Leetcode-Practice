#include<string>
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        vector<vector<int>> adjacencyMatrix(n, vector<int>(n, -n));
        createAdjacencyMatrix(adjacencyMatrix, red_edges, blue_edges);
        queue<pair<int, int>> q;
        q.push({0, 1});
        q.push({0, -1});
        vector<int> result(n, INT_MAX);
        set<string> visited;
        int len = 0; 
        result[0] = 0;
        while(!q.empty()){
            int size = q.size(); 
            len++;
            for(int i=0; i<size; i++){
                auto node = q.front(); 
                q.pop();
                for(int j=1; j<n; j++){
                    
                    if(adjacencyMatrix[node.first][j] == -node.second || adjacencyMatrix[node.first][j] == 0  ){
                        if(visited.find(to_string(j)+to_string(-node.second))== visited.end()){
                            visited.insert(to_string(j)+to_string(-node.second));
                            q.push({j, -node.second});
                            result[j] = min(result[j], len);
                            
                        }
                        else{
                            continue;
                        }

                    }
                }
            }
        }
        for(int i=0; i<n; i++){
            if(result[i] == INT_MAX){
                result[i] = -1;
            }
        }
        return result;
    }
    
    void createAdjacencyMatrix(vector<vector<int>> &adjacencyMatrix, vector<vector<int>> red_edges, vector<vector<int>> blue_edges){
        for(auto edge: red_edges){
            adjacencyMatrix[edge[0]][edge[1]] = 1;
        }
        for(auto edge: blue_edges){
            if(adjacencyMatrix[edge[0]][edge[1]] == 1){
                adjacencyMatrix[edge[0]][edge[1]] = 0; 
            }
            else{
                adjacencyMatrix[edge[0]][edge[1]] = -1;
            }
        }
    }
    
    
};