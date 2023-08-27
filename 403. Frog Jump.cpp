class Solution {
public:
    bool jump(vector<int>& stones, int x, int pre,vector<int> dp[]){
        if(x==stones.size()-1) return true;
        for(auto it : dp[x]){
            if(it==pre) return false;
        }
        for(int i=x+1;i<stones.size() && stones[x]+pre+1>=stones[i];i++){
            if(pre>1 && stones[x]+pre-1==stones[i]){
                if(jump(stones, i, pre-1, dp)) return true;
            }
            if(pre>0 && stones[x]+pre==stones[i]){
                if(jump(stones, i, pre, dp)) return true;
            }
            if(stones[x]+pre+1==stones[i]){
                if(jump(stones, i, pre+1, dp)) return true;
            }
        }
        dp[x].push_back(pre);
        return false;
    }
    bool canCross(vector<int>& stones) {
        int n=stones.size();
        vector<int> dp[n+2];
        return jump(stones, 0, 0, dp);
    }
};
