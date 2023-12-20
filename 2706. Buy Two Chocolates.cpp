class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int ans = money;
        
        sort(prices.begin(),prices.end());     // sort the array 
        
        int sum= prices[0];

        for(int i=1;i<prices.size();i++)
        {
            sum += prices[i];
            if(sum<=money)
            {
                ans = money-sum;
                break;
            }
        }
        return ans;
    }
};
