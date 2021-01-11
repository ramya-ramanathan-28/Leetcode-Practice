class Solution {
public:
    void recursive (vector<string> & result, string digits,vector<string> mappings, string ans, int index){
        if(ans.size() == digits.size()){
            result.push_back(ans);
            return;
        }
        string mapping = mappings[digits[index]-'0'];
        for(int i=0; i<mapping.size(); i++){
            recursive(result, digits, mappings, ans + mapping[i], index+1);
        }
        
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        vector<string> mappings({
            "0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        });
        recursive(result, digits, mappings, "", 0); 
        return result; 
        
    }
};