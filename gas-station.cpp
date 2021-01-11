class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0, target = 1, deficit=gas[0]-cost[0], n=gas.size();
        while(start!=target && target<n){
            if(deficit >=0){                
                target++;
                deficit += gas[target-1] - cost[target-1];
            }
            else{
                start = start - 1;
                if(start < 0){
                    start = n-1;
                }
                deficit+= gas[start] - cost[start];
            }
            
        }
        return deficit>=0? start: -1;
    }
};