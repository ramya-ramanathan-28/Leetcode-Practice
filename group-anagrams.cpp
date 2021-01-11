class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> m;
        vector<int> count(26, 0);
        for(string str: strs){
            fill(count.begin(), count.end(), 0); 
            for(char c: str){
                count[c -'a']++;
            }
            string key = "";
            for(int val: count){
                key.push_back(val+'0');
            }
            if(m.find(key) == m.end()){
                m[key] = vector<string>({str});
            }
            else{
                m[key].push_back(str);
            }
        }
        vector<vector<string>> result;
        for(auto &x: m){
            result.push_back(x.second); 
        }
        return result;
    }
};