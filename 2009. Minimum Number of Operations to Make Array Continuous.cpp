class Solution {
public:
    int minOperations(vector<int>& nums) {

        // Binary search Approach 
        set<int> s;
        for(auto it : nums)
            s.insert(it);
        
        vector<int> v;
        for(auto it : s)
            v.push_back(it);
        int n = nums.size();

        int ans = INT_MAX;
        for(int i = 0; i < v.size(); i++){
            int left = i + 1, right = v.size() - 1;
            int ele = v[i] + n - 1;
            while(left <= right){
                int mid = left + (right - left)/2;
                if(v[mid] == ele){
                    ans = min(ans, n - (mid - i + 1));
                    break;
                }
                else if(v[mid] > ele)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            ans = min(ans, n - (left - i + 1) + 1);
        }

        return ans;
    }
};
