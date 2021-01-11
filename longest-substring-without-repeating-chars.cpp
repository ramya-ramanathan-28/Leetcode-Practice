class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0){
            return 0;
        }
        unordered_map<char, int> m; 
        int i=0, j=0, maxi=0;
        for (int j = 0; j < s.size(); j++){
            if(m.find(s[j]) != m.end()){
                i= max(i,m[s[j]]);
            }
            maxi = max(maxi, j-i+1);
            m[s[j]] = j+1;
            
        }
        return maxi;
    }
};