class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
//     priority_queue<int> pq1;
//     priority_queue<int, vector<int>, greater<int>> pq2;k--;
//    for (int i = 0; i < weights.size() - 1; i++) {
//     pq1.push(weights[i] + weights[i + 1]);
//     pq2.push(weights[i] + weights[i + 1]);
//     if (pq1.size() > k ) {
//         pq1.pop();
//         pq2.pop();
//     }
//     }
//    long long ans1 = 0, ans2 = 0;
//    while (!pq1.empty()) {
//     ans1 += pq1.top();
//     ans2 += pq2.top();
//     pq1.pop();
//     pq2.pop();
//    }
//     return ans2 - ans1;

         vector<long long>ans;
        if(k==1)return 0;
        long long l=0,r=0;
        for (int i=1;i<weights.size();i++){
            ans.push_back(weights[i-1]+weights[i]);
        }
        sort(ans.begin(),ans.end());
        for(int i=0;i<k-1;i++){
            l+=ans[i];
            r+=ans[ans.size()-1-i];
        }
        return (r-l);

    }
};
