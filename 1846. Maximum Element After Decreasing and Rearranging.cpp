class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n=arr.size();
 
        sort(arr.begin(),arr.end());       //sort the array
        
        arr[0]=1;

        for(int i=0;i<(n-1);i++){
            while((arr[i]+1)<arr[i+1])
            {
                arr[i+1]=arr[i]+1;
            }
        }
        
        return arr[n-1];
    }
};
