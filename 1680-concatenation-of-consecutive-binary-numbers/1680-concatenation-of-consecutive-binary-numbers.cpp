class Solution {
public:
    int concatenatedBinary(int n) {
        
        int mod=pow(10,9)+7;
        
        long long int ans=0;
        
        for(int i=0;i<=n;i++)
        {
            int k=i;
            int p=0;
            
            while(k>0)
            {
                k=k/2;
                p++;
            }
            
            ans=((ans<<p)+i)%mod;
        }
        
        return ans%mod;
        
    }
};