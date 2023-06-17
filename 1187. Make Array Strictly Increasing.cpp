class Solution {
private :

//DP + Binary search 
int solve(int curr,int leftVal,vector<int>&arr1,vector<int>&arr2,vector<unordered_map<int,int>>&dp){
    if(curr==arr1.size()) return 0;

    if(dp[curr].find(leftVal)!= dp[curr].end()) return dp[curr][leftVal];
    int  a,b;
    if(arr1[curr]>leftVal){
        a= solve(curr+1,arr1[curr],arr1,arr2,dp);
    }
    else{
        a= INT_MAX;
    }
    int leftUpper = upper_bound(arr2.begin(),arr2.end(),leftVal)-arr2.begin();
    if(leftUpper==arr2.size()){
        //upperbound not found
        b=INT_MAX;
    }
    else{
        b = solve(curr+1,arr2[leftUpper],arr1,arr2,dp);
    }
    if(b==INT_MAX) dp[curr][leftVal]=a;//INT_MAX+1 go out of range 
    else dp[curr][leftVal]=min(a,b+1);
    return dp[curr][leftVal];
}
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
      int n = arr1.size();
      sort(arr2.begin(),arr2.end());
      vector<unordered_map<int,int>>dp(2001);
      int ans = solve(0,INT_MIN,arr1,arr2,dp);
      if(ans==INT_MAX) return -1;
      return ans;
    }
};
