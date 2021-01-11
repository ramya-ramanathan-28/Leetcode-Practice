class Solution {
public:
    void nextPermutation(vector<int>& A) {
        int size = A.size();
        int temp;
        int numIndex = -1;
        for(int i=size-1; i>=1; i--){
            if(A[i]>A[i-1]){
                numIndex= i-1;
                break;
            }
        }
        if(numIndex!= -1){
            int diff = INT_MAX;
            int nextIndex;
            for(int i=numIndex+1; i<size; i++){
                // Have to add = in condition to get in descending order when values are equal
                if(A[i]-A[numIndex]>0 && A[i]-A[numIndex]<=diff){
                    diff = A[i] - A[numIndex]; 
                    nextIndex = i;
                }
            }
            temp = A[numIndex];
            A[numIndex] = A[nextIndex]; 
            A[nextIndex] = temp;
            
        }
        for(int num: A){
            cout<<num<<" ";
        }

        for(int i=numIndex+1, j=size-1; i<j; i++, j--){
                    temp = A[i];
                    A[i] = A[j]; 
                    A[j] = temp;
        }
    }
};
