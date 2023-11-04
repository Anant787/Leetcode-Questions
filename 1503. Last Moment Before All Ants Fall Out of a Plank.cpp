class Solution {
public:
    int getLastMoment(int n, vector<int>& l, vector<int>& r) {
        int ans=0;     // to store the answer

        for(int i=0;i<l.size();i++){
            if(l[i]>ans){ 
                ans=l[i];               // left element
            }
        }
        for(int i=0;i<r.size();i++){
            if(n-r[i]>ans)
            {
                ans=n-r[i];          // right element
            }
        }
        return ans;
    }
};
