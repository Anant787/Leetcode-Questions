class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if (n < 3){
            return 0;
        }
        
        stack<int> st;           // monotonic stack
        int third = INT_MIN;       // set as minimum

        for (int i=n-1; i>=0; i--)       ///iterate from last
        {
            int currEle = nums[i];
            if (currEle < third){
                return true;
            }
            while (!st.empty() && st.top() < currEle){
                third = st.top();
                st.pop();
            }
            st.push(currEle);
        }

        return false;
    }
};
