class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long res = 0;
        int count = 0;
        int n = happiness.size();
        sort(happiness.begin(), happiness.end());
        int curr = n-1;
        for(int i = 0; i < k; i++) {
            int val = happiness[curr] - count;
            if(val < 0) break;

            res += val;
            curr--;
            count++;
        }

        return res;
    }
};
