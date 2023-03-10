class Solution {
public:
    int maxDepth(string s) {
        stack<char>st;   //stack of character type
        int ans=0;   //for returing the anwwer
        int currmax=0,max_depth=0;

        for(int i=0;i<s.size();i++)
        {
            if(s[i] == '(')
            {
                st.push(s[i]);
                currmax++;
               // ans = ans > st.size() ? 0 : st.size(); 
            }

            else if(s[i] == ')')
            {
                st.pop();
                if(currmax>max_depth)
                {
                    max_depth = currmax;
                }
                currmax--;
            }
        }
        return max_depth;
    }
};
