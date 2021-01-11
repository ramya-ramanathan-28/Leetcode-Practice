class Solution {
public:   
    int leastInterval(vector<char>& tasks, int n) {
        map<char, int> m; 
        vector<pair<char, int>> v;
        vector<char> finalAnswer;
        for(char task: tasks){
            if(m.count(task)){
                m[task]++;
            }
            else{
                m[task] = 1;
            }
        }
        int cycles = 0;
        priority_queue<int> pq;
         for(auto elem : m)
            pq.push(elem.second);
        
        while(!pq.empty()){
            vector<int> temp;
            for(int i=0; i<n+1; i++){
                if(!pq.empty()){
                    temp.push_back(pq.top());
                    pq.pop();
                }
            }
            
            for(int i:temp){
                if(--i){
                    pq.push(i);
                }
            }
                            
            cycles+= pq.empty() ? temp.size() : n+1;
        }
        
        return cycles;
    }
};