class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<pair<double, double>> v;
        int n = quality.size();
        for(int i=0; i<n; i++) {
            double ratio = (double)wage[i] / (double)quality[i];
            v.push_back({ratio, (double)quality[i]});
        }

        sort(v.begin(), v.end());

        double ans = DBL_MAX;
        double qSum = 0;
        priority_queue<double> pq;
        for(int i=0; i<n; i++) {
            qSum += v[i].second;
            pq.push(v[i].second);

            if(pq.size() > k) {
                qSum -= pq.top();
                pq.pop();
            }

            if(pq.size() == k) {
                double cost = qSum * v[i].first;
                if(cost < ans) {
                    ans = cost;
                }
            }
        }

        return ans;
    }
};
