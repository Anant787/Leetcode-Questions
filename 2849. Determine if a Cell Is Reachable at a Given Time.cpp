class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int maxi= max(abs(sx-fx), abs(sy-fy));

        if(maxi==0 && t==1) return false;
        
        if(t < maxi) return false;
        
        return true;
    }
};
