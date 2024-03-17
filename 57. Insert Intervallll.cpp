class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>res;
        int i = 0, n =intervals.size();

        while(i<n && intervals[i][1] < newInterval[0])
        {
            res.push_back(intervals[i]);
            i++;
        }

        vector<int> mini = newInterval;
        while(i<n && intervals[i][0] <= newInterval[1])
        {
            mini[0] = min(mini[0],intervals[i][0]);
            mini[1] = max(mini[1],intervals[i++][1]);
        }
        res.push_back(mini);

        while(i<n)
        {
            res.push_back(intervals[i++]);
        }

        return res;
        
    }
};
