class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        /*
        Let dp[i] be the solution for the prefix of the array that ends at index i, if the element at index i is in the subsequence.
        dp[i] = nums[i] + max(0, dp[i-k], dp[i-k+1], ..., dp[i-1])
        Use a heap with the sliding window technique to optimize the dp.
        */
        priority_queue<pair<int,int>> pq;   //max heap
        int n = nums.size();
       
        pq.push({nums[0], 0});
        int ans = nums[0];
        for (int i=1; i<n; i++){
           
            while(!pq.empty() && i-pq.top().second >k){
                pq.pop();
            }
            if (!pq.empty()){
                nums[i] += max(0,pq.top().first);
            }
           
            ans = max(ans,nums[i]);
            pq.push({nums[i],i});
        }
       return ans;
    }
};
