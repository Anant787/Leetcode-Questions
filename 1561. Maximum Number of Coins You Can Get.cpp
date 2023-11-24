class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size();

        sort(piles.rbegin(),piles.rend());      // sorting

        int ans = 0;
        int k = n/3;

        for(int i = 1;i<n-k;i+=2)
        {
            ans += piles[i];
        }

        return ans;
    }
};
