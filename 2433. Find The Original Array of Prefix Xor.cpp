class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        
        int n=pref.size();  // size of arry 
        vector<int> arr(n);

        arr[0]=pref[0];       // store the first element
        for(int i=1;i<n;i++)
        {
            arr[i]=pref[i] ^ pref[i-1];         //xor 
        }

        return arr;
    }
};
