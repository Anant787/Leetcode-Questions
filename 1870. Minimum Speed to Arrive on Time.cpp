class Solution {
public:
    bool isFeasible(int speed ,vector<int>& dist, double hour){
        double time_taken = 0;
        for(auto it : dist){
            time_taken += ((double)it / speed);
            if(time_taken > hour)
                return false;
            time_taken = ceil(time_taken);
        }
        return true;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size(), ll = 1, ul = 1e7, mid = 0, ans = -1;
        while(ll <= ul){
            mid = ll + ul >> 1 ;
            if(isFeasible(mid, dist, hour)){
                ul = mid - 1;
                ans = mid;
            }
            else
                ll = mid + 1;
        }
        return ans;
    }
};
