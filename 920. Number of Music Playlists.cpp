class Solution {
public:
//DP
#define ll long long
#define mod 1000000007
    ll dp[101][101];

    ll sol(int len, int num, int goal, int n, int k) {
        if (len == goal) {
            return num == n;
        }

        if (dp[len][num] != -1) {
            return dp[len][num];
        }

        ll ans = (sol(len + 1, num, goal, n, k) * max(0, num - k)) % mod;
        ll res = (sol(len + 1, num + 1, goal, n, k) * (n - num)) % mod;

        return dp[len][num] = (ans + res) % mod;
    }

    int numMusicPlaylists(int n, int goal, int k) {
        memset(dp, -1, sizeof(dp));
        return sol(0, 0, goal, n, k);
    }
};
