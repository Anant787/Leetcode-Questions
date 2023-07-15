class Solution {
public:
    //Binary Search 
    // next index
    int BinarySearch(int i, vector<vector<int>>& e, int val){
        int st = i;
        int end = e.size() - 1;
        int nextIdx = -1;

        while(st <= end){
            int mid = st + (end - st)/2;
            if(e[mid][0] > val){
                nextIdx = mid;
                end = mid - 1;
            }
            else{
                st = mid + 1;
            }
        }

        return nextIdx;
    }

    // keep that index or not
    int solve(int idx, vector<vector<int>>& e, int k,vector<vector<int>>& dp){
        if(idx >= e.size() || k <= 0 || idx ==-1){
            return 0;
        }
        
        if(dp[idx][k] != -1){
            return dp[idx][k];
        }

        int nextIdx = BinarySearch(idx + 1, e, e[idx][1]);
        
        int take = e[idx][2] + solve(nextIdx , e, k-1, dp);
        
        
        int notTake = 0 + solve(idx + 1, e, k, dp);

        return dp[idx][k] = max(take, notTake);
    }

    int maxValue(vector<vector<int>>& e, int k) {
        //sorting on basis of start

        sort(e.begin(), e.end());
        int n = e.size();
        vector<vector<int>> dp(n , vector<int>(k+1, -1));
        return solve(0, e, k, dp);



    }
};
