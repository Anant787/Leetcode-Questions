class Solution {
public:
    //Binary search Approach
    bool check(int mid, int n, int ind, int maxi){
        long sum = mid;

        long r=n-ind-1;
        long l=ind;

        long ls=0;//sum on left
        long rs=0;//sum on right
        long m=mid-1;
            
        if(r<=m)
            rs=m*(m+1)/2 - (m-r)*(m-r+1)/2;
        else
            rs=m*(m+1)/2 + 1*(r-m);
            
        if(l<=m)
            ls=m*(m+1)/2 - (m-l)*(m-l+1)/2;
        else
            ls=m*(m+1)/2 + 1*(l-m);
            
        sum+=ls+rs;

        if(sum <= maxi){
            return true;
        }
        return false;
    }

    int maxValue(int n, int index, int maxSum) {
        int s = 1;
        int e = maxSum;

        int ans = 0;

        while(s<=e){
            int mid = s + (e-s)/2;

            if(check(mid , n, index, maxSum)){
                ans = mid;
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }

        return ans;
    }
};
