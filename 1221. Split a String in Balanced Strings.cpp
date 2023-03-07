class Solution {
public:
    int balancedStringSplit(string s) {

        //Hash map Approach 

        map<char,int>mp;
        mp['R'] = 0;
        mp['L'] = 0;

        int count=0;

        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;

            if(mp['R'] == mp['L'])
            {
                count++;
                mp['R']=0;
                mp['L'] =0;
            }
        }
        return count;

        // Naive Approach

        // int count=0;
        // int R = 0;
        // int L = 0;

        // for(int i=0;i<s.size();i++)
        // {
        //     if(s[i]== 'R')
        //     {
        //         R++;
        //     }
        //     if(s[i] == 'L')
        //     {
        //         L++;
        //     }
        //     if(L==R)
        //     {
        //         count++;
        //         R=0;
        //         L=0;
        //     }
        // } 
        // return count;
        
    }
};
