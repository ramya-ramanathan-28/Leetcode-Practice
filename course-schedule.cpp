class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> visited(numCourses, false);
        vector<int> adjacencyList[numCourses];
        makeAdjacencyList(prerequisites, adjacencyList); 
        vector<int> s;
        bool isCyclic = false; 
        for(int i=0; i<numCourses; i++){
            if(!visited[i]){
                dfs(visited, s, i, adjacencyList, isCyclic);
            }
            if(isCyclic){
                return false;
            }
        }
        return !isCyclic;
        
    }
    
    void makeAdjacencyList(vector<vector<int>> prerequisites, vector<int> adjacencyList[]){
        for(auto element: prerequisites){
            adjacencyList[element[1]].push_back(element[0]);
        }
    }
    
    void dfs(vector<bool>& visited, vector<int>s, int i, vector<int> adjacencyList[], bool& isCyclic){
        s.push_back(i);
        visited[i] = true;
        for(auto j=adjacencyList[i].begin(); j!=adjacencyList[i].end(); j++){
             for(int element: s){
                if(element == *j){
                    isCyclic = true;
                    return;
                }
            }
            if(!visited[*j]){
                dfs(visited, s, *j, adjacencyList, isCyclic);
            }
           
        }
        s.pop_back();
        
    }
};