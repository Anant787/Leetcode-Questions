class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        
        sort(arr.begin(),arr.end());  //sort the array 
        
        int n=arr.size();
        
        int diff=arr[1]-arr[0];   //find the common diff
        
        for(int i=2;i<n;i++)
        {
            if(arr[i]-arr[i-1] !=diff)   //check the condition
            {
                return false;
            }
        }
        return true;
        
    }
};
