class Solution {
public:
    int totalFruit(vector<int>& tree){
        map<int, int> fruits;
        int i=0, j=0, max = 0, minimum = tree.size()-1;
        while(j<tree.size()){
            if(fruits.size()<=2){
                fruits[tree[j]] = j;
                j++;
            }
            if(fruits.size() > 2){
                minimum = tree.size()-1;
                for(auto& x: fruits){
                    minimum = min(minimum, x.second);
                }
                i = minimum +1;
                fruits.erase(tree[minimum]);
            }
            if(j-i>max){
                max = j-i;
                
            }

        }
        return max; 
    }
//     int totalFruit(vector<int>& tree) {
//         int fruit1=-1, fruit2=-1, fruit2count = 0, fruitcount=0, max = 0; 
        
        
//         for(int fruit: tree){
//             if(fruit == fruit1 || fruit == fruit2){
//                 max++;
//             }
//             else{
//                 max = fruit2count + 1;
//             }
            
            
//             if(fruit == fruit2){
//                 fruit2count++;
//             }
//             else{
//                 fruit1 = fruit2; 
//                 fruit2 = fruit; 
//                 fruit2count = 1; 
//             }
            
//             if(max> fruitcount){
//                 fruitcount = max; 
//             }
//         }
//         return fruitcount; 
//     }
};