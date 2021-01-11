class Solution {
public:
    void calcSum(vector<vector<int>>& result, vector<int> & candidates, vector<int>& current, int target, int curr_index){
        if(target == 0){
            result.push_back(current); 
            return;
        }
        else if(target<0){
            return;
        }
        
        for(int i = curr_index; i<candidates.size(); i++){
//             i == curr_index because the number must be included each time, when previous one has been included. 
            if(i==curr_index || candidates[i] !=candidates[i-1]){
                current.push_back(candidates[i]); 
                calcSum(result, candidates, current, target - candidates[i], i+1);
                current.pop_back(); 
            }
        }
        
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result; 
        if(candidates.size() == 0){
            return result; 
        }
        sort(candidates.begin(), candidates.end()); 
        vector<int> current; 
        calcSum(result, candidates, current, target, 0);
        return result;
    }
};