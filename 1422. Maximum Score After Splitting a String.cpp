class Solution {
public:
    int maxScore(string s) {

        int n = s.size();
        int count = 0;

        for(int i =0;i<n;i++)
        {
            if(s[i]=='1')
            {
                count++;
            }
        }

        int left =0,right = count;

        int score = left+right;

        vector<int> v;

        for(int i =0;i<n-1;i++)
        {
            if(s[i]=='0')
            {
                left++;
               // cout << "left = "<<left<<endl;
            }
            else
            {
                right--;
                //cout << "right = "<<right<<endl;
            }

            int sc = left+right;
            v.push_back(sc);
        }

        for(int i =0;i<v.size();i++)
        {
            cout<<v[i]<<endl;
        }

        sort(v.begin(),v.end());

        return v[v.size()-1];
        
    }
};
