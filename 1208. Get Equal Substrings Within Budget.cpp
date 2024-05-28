class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n=s.size();
        int i=0,j=0;
        int maxL=0;

        while(j<n)
        {
            maxCost-=abs((s[j]-t[j]));

            while(i<=j && maxCost < 0)
            {
                maxCost += abs((s[i]-t[i]));
                i++;
            }

            maxL=max(maxL,j-i+1);
            
            j++;
        }
        return maxL;
    }
};
