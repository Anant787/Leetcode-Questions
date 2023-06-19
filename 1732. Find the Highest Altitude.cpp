class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        // vector<int>v;
        // int n= gain.size();
        // v[0] = gain[0];
        // int sum =0;
        // int maxi = 0;

        // for(int i=1;i<n;i++)
        // {
        //     sum = gain[i]+gain[i-1];
        //     v.push_back(sum);
        //     maxi = max(maxi,v[i]);
        // }

        // return maxi;

        int n=gain.size();
        int maxi=0;
        int sum=0;

        for(int i=0;i<n;i++){
            sum+=gain[i];
            maxi=max(maxi,sum);
        }
        return maxi;
         
    }
};
