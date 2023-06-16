class Solution {
public:
    //very hard question
    int numOfWays(vector<int>& nums) {
        int n_ways = solve(nums);
        return n_ways - 1;
    }

    int solve(vector<int>& nums) {
        int mod = 1000000007;
        int n = nums.size();
        if (n <= 2) {
            return 1;
        }
        vector<int> lwr, upr;
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[0]) {
                lwr.push_back(nums[i]);
            } else {
                upr.push_back(nums[i]);
            }
        }
        int n_lwr, n_upr;
        n_lwr = solve(lwr);
        n_upr = solve(upr);
        long long ans = 0;
        ans = (long long) n_lwr*n_upr % mod;
        int lm = lwr.size();
        int ln = upr.size();
        int comb = combination(lm+ln, lm, mod);
        ans = (ans*comb) % mod;
        return ans;
    }

    int combination(int m, int n, int prime) {
        long long nom = 1, denom = 1;
        for (int i = 0; i < min(n, m-n); i++) {
            nom *= (m-i);
            nom %= prime;
            denom *= (i+1);
            denom %= prime;
        }
        int inv_denom = inverse(denom, prime);
        long long comb = nom * inv_denom % prime;
        return comb;
    }

    int inverse(int n, int prime) {
        int old_r, r, old_s, s, old_t, t;
        old_r = n;
        r = prime;
        old_s = 1;
        s = 0;
        old_t = 0;
        t = 1;
        while (r != 0) {
            int q = old_r / r;
            parallel_assign(r, old_r - q*r, old_r, r);
            parallel_assign(s, old_s - q*s, old_s, s);
            parallel_assign(t, old_t - q*t, old_t, t);
        }
        return old_s < 0 ? (old_s+prime) : old_s;
    }

    void parallel_assign(int x, int y, int& a, int& b) {
        a = x;
        b = y;
    }
};
