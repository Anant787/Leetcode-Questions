// class Solution {
// public:
//     int numFactoredBinaryTrees(vector<int>& arr) {
//         if(arr.size() == 1) return 1;

//         /*
//         First, we need to sort the given array, and 
//         create a hashmap to store how many binary trees 
//         can be made with that integer as a root.
//         */

//         sort(arr.begin(), arr.end());
//         unordered_map<int, long long> mp;
//         // hash map

//         /*
//         As we can make atleast one binary tree with each integer 
//         with null nodes, we increase the value to 1 for 
//         every integer in the map.
//         */

//         for(int i = 0; i<arr.size(); i++){
//             mp[arr[i]] = 1;
//         }

//         /*
//         Now, we need to find how many binary trees can be made 
//         with each integer as a root, 
//         and we can find that by multiplying the number of trees 
//         that can be formed from their children as roots.
//         We leave the first integer because it can't have any 
//         children because it is the smallest in the array. 

//         Now, we have to find the children nodes, and add the 
//         product of the children values to the hashmap.
//         */

//         for(int i = 1; i<arr.size(); i++){
//             for(int j = 0; j<i && arr[j]<=sqrt(arr[i]); j++){
//                 if(arr[i] % arr[j] == 0 && mp.find(arr[i]/arr[j]) != mp.end()){
//                     if(arr[i]/arr[j] == arr[j]){
//                         mp[arr[i]] += (mp[arr[j]] * mp[arr[i]/arr[j]]); 
//                     }
//                     else{
//                         mp[arr[i]] += (mp[arr[j]] * mp[arr[i]/arr[j]]) * 2; 
//                     }
//                 }
//             }
//         }

//         /*
//         Now, we just have to return the sum of all the possible binary trees 
//         for each integer as root, modulo by 10^9+7.
//         */

//         long long int ans = 0;
//         for(auto it: mp){
//             ans+=it.second;
//         }
//         return ans%(1000000007);
//     }
// };

class Solution {
public:
    int mod = 1e9 + 7;
    int dp[1001];
    unordered_map<int, int> mp;
    int solve(vector<int> &arr, int i){
        if(dp[i] != -1)
            return dp[i];
        long long a = 1;
        for(int j=0; j<i; j++){
            if(arr[i] % arr[j] == 0 && mp.count(arr[i] / arr[j])){
                a = (a + (long long)solve(arr, j) * solve(arr, mp[arr[i] / arr[j]]) % mod) % mod;
            }
        }

        return dp[i] = a;
    }
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        for(int i=0; i<arr.size(); i++){
            mp[arr[i]] = i;
        }
        long long ans = 0;
        memset(dp, -1, sizeof dp);
        for(int i=0; i<arr.size(); i++)
            ans = (ans + solve(arr, i)) % mod;
        
        return ans;
    }
};
