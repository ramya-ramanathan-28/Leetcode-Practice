class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false); 
        visited[0] = true;
    
        int stack_top;
        
        stack<int> s; 
        s.push(0); 
        while(!s.empty()){
            stack_top = s.top();
            s.pop();
            for(int key: rooms[stack_top]){
                if(!visited[key]){
                    visited[key] = true;
                    s.push(key); 
                }
            }
        }
        
        
        for(bool seen: visited){
            if(!seen)
                return false;
        }
        return true; 
    }
};