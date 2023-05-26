class Solution {
public:

    //Dynamic Programming
    int n;
    int helper(vector<int>& piles,vector<vector<int>>& memo,vector<int>& sum, int start, int M){
        if(start == n-1) return piles[start];
        if(memo[start][M] != -1) return memo[start][M];
        
        //if M> number of piles left, take the suffix sum directly
        if(n-start<= 2*M) return sum[start];
        
        int ans =INT_MAX;
        //can take minimum 1, maximum 2M piles
        for(int i=1;i<=2*M;i++){
            //to minimize opponent's choice
            ans =min(ans, helper(piles,memo,sum,start+i,max(M,i)));
        }
        
        //result is (sum - opponent's score)
         return memo[start][M] =sum[start] - ans;
    }
    
    int stoneGameII(vector<int>& piles) {
        n=piles.size();
        
        //calculate suffix sum        
        vector<int> sum(n);

        sum[n-1] = piles[n-1];
        
        for(int i=n-2;i>=0;i--)
        {
            sum[i] = piles[i] + sum[i+1];
        }
        
        //<start index,M>
        vector<vector<int>> memo(n,vector<int>(2*n,-1));
        return helper(piles,memo,sum,0,1);
    }
};
