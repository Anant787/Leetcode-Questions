class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int cnt=0,ans=0,n=nums.size();
        unordered_map<int,int> m;
        for(int l=0,r=0;r<n;r++){
            m[nums[r]]++;
            if(m[nums[r]]==1)cnt++;
            while(cnt>k){
                m[nums[l]]--;
                if(m[nums[l]]==0)cnt--;
                l++;
            }
            if(cnt==k){
                int t=l;
                while(cnt==k){
                    ans++;
                    m[nums[t]]--;
                    if(m[nums[t]]==0)cnt--;
                    t++;
                }
                while(t>l){       //Backtracking
                    m[nums[t-1]]++;
                    if(m[nums[t-1]]==1)cnt++;
                    t--;
                }
            }
        }
        return ans;
    }
};
