class Solution {
    
    
    int dp[102];
    int decode(string& s, int idx, int n)
    {
        if(idx < n && s[idx] == '0') return 0;
        if(idx >= n)
            return 1;
        
        if(dp[idx] != -1) return dp[idx];
        
        int ways = 0;
        
        // Pick single
        if(s[idx] != '0') ways = decode(s, idx+1, n);
            
        // Pick couple
        if(idx+1 < n && ((s[idx] == '1' && s[idx+1] <= '9') || (s[idx]=='2' && s[idx+1] < '7')))
           ways += decode(s, idx+2, n);
           
        return dp[idx] = ways;
    }
 
        
//     int decode(string&s,int index,int n)
//     {
//         if(index<n  && s[index]=='0')
//         {
//             return 0;
//         }
        
//         if(index >= n) return 1;
        
//         int count=0;
        
//         //for digits 0 to 9
        
//         count += decode(s,index+1,n);
        
//         // for digit 10 to 26
//         if(index+1<n &&((s[index]=='1' && s[index+1] <= '9')  || (s[index] == '2' && s[index+1]<='6')))
//         {
//             count +=decode(s,index+2,n);
//         }
        
//         return count;
//     }
public:
    int numDecodings(string s) {
        
         int n = s.size();
        memset(dp, -1, sizeof(dp));
        return decode(s, 0, n);
        
//         int n = s.size();
        
//         return decode(s,0,n);
        
    }
};