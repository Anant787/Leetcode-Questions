class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        
        for(int i = 2;i<=n;i++)
        {
            string laststring = ans;
            int l = ans.size();
            int j=0;
            ans = "";
            
            while(j<l)
            {
                int count = j;
                while(j<l  && laststring[j] == laststring[count])
                {
                    count++;
                }
                ans += to_string(count-j) +laststring[j];
                j=count;
            }
        }
        return ans;
        
    }
};