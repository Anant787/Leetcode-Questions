//hard problem

class Solution {
public:
    // O(max(a,b))
    int n;
    int gcd(int a,int b){
        if(b==0)
        return a;
        return gcd(b,a%b);
    }
    int func(vector<vector<int> > &gcds,int mul,vector<int> &store,int mask){
        if(mul==0)
        return 0;

        if(store[mask]!=-1)
        return store[mask];

        int ans = 0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int a = mask&1<<i;
                int b = mask&1<<j;
                if(!(mask&1<<i)&& !(mask&1<<j)){// both are usable
                    int cur = gcds[i][j]; // ----- O(1) fetch gcds Now at O(1) time complexity
                    int cur_selection = func(gcds,mul-1,store,mask|1<<i|1<<j);
                    ans = max(ans,mul*cur + cur_selection);
                }
            }
        }
       
        return store[mask] = ans;

    }
    int maxScore(vector<int>& nums) {
        n = nums.size();
        vector<vector<int> > gcds(n,vector<int>(n));
        // calculate all gcds of 2 numbers
        // don't calculate gcd of same number
        // after use mark number as 0 which means not to use the number

        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                gcds[i][j] = gcd(nums[i],nums[j]);
            }
        }
        vector<int> store(1<<15,-1);
        int mask =0;
        return func(gcds,n/2,store,mask);
    }
};
