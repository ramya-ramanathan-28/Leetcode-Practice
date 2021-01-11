class Solution {
public:
    int compress(vector<char>& chars) {
        int index=0, i=0, j=0;
        int len = chars.size();
        while(i<len){
              j=i;
            while(j<len && chars[i] == chars[j]){
                j++;
            }
            chars[index++] = chars[i];
            if(j-i>1){
                string count = to_string(j-i);
                for(char c: count){
                    chars[index++] = c;
                }
            }
            
            i=j;
        }
        return index;
    }
};