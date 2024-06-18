class Compare {
public:
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.second < b.second;
    }
};
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int ans = 0, n = profit.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
        for (int i = 0; i < n; i++)
        {
            pq.push({difficulty[i], profit[i]});
        }
        sort(worker.begin(), worker.end(), greater<>());
        for (int i = 0; i < worker.size(); i++)
        {
            int res = 0;
            while (!pq.empty() && pq.top().first > worker[i])
            {
                pq.pop();
            }
            if (!pq.empty())
            {
                res = pq.top().second;
            }
            ans += res;
        }
        return ans;
    }
};
