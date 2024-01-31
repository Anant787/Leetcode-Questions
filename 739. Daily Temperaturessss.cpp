class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temper) {
        int n = temper.size();
        vector<int>ans;
        stack<int>s;

        for(int i=n-1;i>=0;i--)
        {
            if(s.empty())
            {
                s.push(i);
                ans.push_back(0);
            }
            else
            {
                while(!s.empty() && temper[s.top()]<= temper[i])
                {
                    s.pop();
                }

                if(s.empty())
                {
                    s.push(i);
                    ans.push_back(0);
                }
                else
                {
                    ans.push_back(s.top()-i);
                    s.push(i);
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};
