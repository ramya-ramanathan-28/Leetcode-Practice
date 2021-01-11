class Solution {
public:
   int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
       map<string, vector<string>> combi;
       int l = beginWord.size();
       
       for(auto word: wordList) {
           for(int i = 0; i< l; ++i) {
               string generic_combi =  word.substr(0, i) + "*" + word.substr(i+1, l-i-1);
               if(combi.find(generic_combi) == combi.end()) {
                   combi[generic_combi] = {};
               }
               combi[generic_combi].emplace_back(word);
           }
       }

       int count = 1;
       queue<string> q;
       q.push(beginWord);
       set<string> visited;
       visited.insert(beginWord);
       
       while(!q.empty()) {
           int size = q.size();
           for(int i = 0; i < size; ++i) {
               string word = q.front();
               q.pop();
               
               if(word == endWord) {
                   return count;
               }
               for(int j = 0; j < l; ++j) {
                   string generic_combi =  word.substr(0, j) + "*" + word.substr(j+1, l-j-1);
                   vector<string> allNeighbors = combi[generic_combi];
                   for(string neigh: allNeighbors) {
                       if(visited.find(neigh) == visited.end()) {
                           q.push(neigh);
                           // Remember to put visited here
                           visited.insert(neigh);
                       }
                   }
               }
           }
           ++count;
       }
       
       return 0;
   }
};
