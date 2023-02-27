class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();

        if(n==1)
        {
            return 0;
        }
        int maxa=0,count=0,curr=0;
        for(int i=0;i<n-1;i++)
        {
            maxa = max(nums[i]+i,maxa);
            if(curr == i)
            {
                curr = maxa;
                count++;
            }
            if(curr > n-1)
            {
                return count;
            }
        }
        return count;
    }
};
