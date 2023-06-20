class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
    //    int n = nums.size();
    //    vector<int> avg(n, -1); vector<long long> pre(n+1 , 0);
    //    for(int i =1 ; i <= n ; i++){
    //        pre[i] = pre[i-1] + nums[i-1];
    //    }

    //    //we have done +1 to shift the prefix sum array by one step to right, so that we have pre[0] = 0 and pre[1] = pre[0] + nums[0]; 
    //    for(int i = k ; i < n-k; i++){
    //        avg[i] = (pre[i+k+1] - pre[i-k])/(2*k+1);
    //    }

    //    return avg;


    //Sliding window
        
        vector<int> ans(nums.size(),-1);

        // if k exceed nums.size.
        if(k>=nums.size()) return ans;

        int i=0,j=0;

        // to handle integer overflow.
        long long sum =0;

        while(j<nums.size())
        {
            sum += nums[j];

            if(j-i<2*k) j++;
            
            //
            else if(j-i==2*k)
            {
              ans[j-k] = sum / ((k*2)+1);
               sum -= nums[i];

                // shift the window.
               i++; j++;
            }
        }
        return ans;
    }
};
