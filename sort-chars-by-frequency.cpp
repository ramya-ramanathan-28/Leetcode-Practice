 struct compare  
 {  
   bool operator()(const pair<char,int>& l, const pair<char,int>& r)  
   {  
       return l.second < r.second;  
   }  
 };   
class Solution {
public:
    string frequencySort(string s) {
        map<char, int> m; 
        for(char c: s){
            if(m.find(c)==m.end())
                m.insert({c, 1});
            else
                m[c]++;
        }
        priority_queue<pair<char, int>, vector<pair<char, int>>, compare> pq;
        for(auto const& x: m){
            cout<<x.first<<" "<<x.second<<endl;
            pq.push(make_pair(x.first, x.second)); 
        }
        string finalString = "";
        cout<<pq.size();
        while(!pq.empty()){
            auto val = pq.top();
            pq.pop();
            finalString+=string(val.second, val.first);
        };
        return finalString; 
        
    }
};