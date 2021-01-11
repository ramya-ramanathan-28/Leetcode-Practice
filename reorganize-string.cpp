
struct CompareValues { 
    bool operator()(pair<char, int> p1, pair<char, int> p2) 
    { 
        return p1.second < p2.second; 
    } 
}; 
class Solution {
public:
    string reorganizeString(string S) {
        map<char, int> m;
        for(char c: S){
            if(m.count(c)){
                m[c]++;
            }
            else{
                m[c] = 1;
            }
        }
        
        priority_queue<pair<char, int>, vector<pair<char, int>>, CompareValues> pq;
        for(auto p: m){
            pq.push({p.first, p.second});
        }
        pair<char, int> top, next;
        string returnVal = "";
        while(pq.size()>1){
            top = pq.top();
            pq.pop();
            next = pq.top();
            pq.pop();
            returnVal+= top.first;
            returnVal+= next.first;
            if(--top.second>0){
                pq.push(top);
            }
            if(--next.second>0){
                pq.push(next);
            }
        }
        if(!pq.empty()){
            top =pq.top(); 
            pq.pop();
            if(top.second>1){
                return "";
            }
            returnVal+= top.first;
        }
        return returnVal;
    }
};