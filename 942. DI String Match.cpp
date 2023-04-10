class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.size();
        int lp = 0;
        int rp = n;

        vector<int>v;
        
        for(int i=0;i<n;i++)
        {
            if(s[i] == 'I')
            {
                v.push_back(lp);
                lp++;
            }
            else if(s[i] == 'D')
            {
                v.push_back(rp);
                rp--;
            }
        }

        if(s[n-1] == 'I')
        {
            v.push_back(lp);
        }
        else{
            v.push_back(rp);
        }

        return v;
     
        
    }
};
