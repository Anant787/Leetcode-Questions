class Solution {
public:
    //Map Solution
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int> m;
        int ans=1;
        for(int i=arr.size()-1;i>=0;i--){
            m[arr[i]]=max(m[arr[i]],m[arr[i]+difference]+1);
            ans=max(ans,m[arr[i]]);
        }
        return ans;
    }
};
