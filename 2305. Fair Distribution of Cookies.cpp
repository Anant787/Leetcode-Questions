class Solution {
public:
    //binary search
    bool isPossible(vector<int> &arr, int mid, int k){
        int n = arr.size();
        do{
            int count = 1;
            int sum = 0;
            for(int i=0; i<n; i++){
                if(arr[i]>mid)
                    return false;
                sum = sum + arr[i];
                if(sum>mid){
                    sum = arr[i];
                    count++;
                }
            }
            if(count<=k)
                return true;
        } while(next_permutation(arr.begin(), arr.end()));
        return false;
    }

    int distributeCookies(vector<int>& cookies, int k){
        sort(cookies.begin(), cookies.end());
        int sum = 0;
        int n = cookies.size();
        int s = 0;
        for(int i=0; i<n; i++){
            // s = min(s, cookies[i]);
            sum = sum + cookies[i];
        }
        int e = sum;
        int ans = 0;
        while(s<=e){
            int mid = (s+e)/2;
            if(isPossible(cookies, mid, k)){
                ans = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return ans;
    }
};


// class Solution {
// public:

    
//     void dfs(vector<int> &arr, int k, int ind, vector<int> &v, int &ans){
//         int n = arr.size();
//         if(ind==n){
//             int maxi = INT_MIN;
//             for(int i=0; i<k; i++){
//                 maxi = max(maxi, v[i]);
//             }
//             ans = min(ans, maxi);
//             return;
//         }

//         for(int i=0; i<k; i++){
//             v[i] = v[i] + arr[ind];
//             dfs(arr, k, ind+1, v, ans);
//             v[i] = v[i] -  arr[ind];
//         }
//     }

//     int distributeCookies(vector<int>& cookies, int k) {
//         int ans = 1e6;
//         vector<int> v(k, 0);
//         dfs(cookies, k, 0, v, ans);
//         return ans;
//     }
// };
