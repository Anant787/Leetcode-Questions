class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int size= arr.size();
        double required= (0.25)* size;      // condition 

        int i=0, j=1, count=1;
        
        while(j<size)
        {
            if(arr[i]!=arr[j]){
                count=1;
                i=j;
            }
            else{
                count++;
                if(count > required){
                    return arr[i];
                }
            }
            j++;
        }
        return arr[0];
    }
};
