class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        double l = 0, h = 1.0; //range of possible quotients

        while (l < h) {
            double mid = (l + h) / 2;
            vector<int> cnt = solve(arr, mid);

            if (k < cnt[0]) {
                h = mid;
            } else if (k > cnt[0]) {
                l = mid;
            } else {
                return {cnt[1], cnt[2]};
            }
        }
        return {};
    }

    vector<int> solve(vector<int>& arr, double target) {
        int count = 0;
        int i = 0;
        int n = arr.size();
        int num = arr[0];
        int den = arr[n - 1];

        for (int j = 1; j < n; j++) {
            while (i < j && arr[i] <= arr[j] * target) { //we are counting the no. of fractions less than target/mid for the first time.
                i++;
            }
            count += i;  // in every iteration 0-i will be added and we are also not calculation for every 0-i rather previous value of i + new fractions is getting added so we are calculating more efficiently
            if (i > 0 && arr[i - 1] * den > arr[j] * num) {  // to return num and denom. we initialized with extreme values and now updating it with i-1 and j...
                num = arr[i - 1];
                den = arr[j];
            }
        }
        return {count, num, den};
    }
};
