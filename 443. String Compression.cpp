class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int i =0 , j=0;
        string ans = "";

        while(i<n)
        {
            ans += chars[i];
            char curr = chars[i];
            int count = 0;
            while(j<n && chars[j] == curr)
            {
                count++;
                j++;
            }
            if(count>1)
            {
                ans += to_string(count);
                i=j;  //go to the position where j start and continue form that
            }
            if(count==1)
            {
                i++;
            }
        }

        chars.clear();
        for(auto it : ans)
        {
            chars.push_back(it);
        }

        return ans.size();

        
    }
};
