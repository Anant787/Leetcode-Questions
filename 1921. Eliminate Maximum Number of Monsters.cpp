class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n=dist.size();
        vector<double> vp(n);

        for(int i=0;i<n;i++){
            vp[i] = (double)dist[i]/speed[i];      // store the time
        }
        
        sort(vp.begin(),vp.end());      // sort the time

        int ans=0,cur=0;
        
        for(int i=0;i<n;i++){
            if(i==0 && vp[i] >= cur)
            {
                cur++;
            }
            else if(vp[i] <= cur)
            {
                return i;
            }
            else
            {
                cur++;
            }
        }
        return n;
    }
};
