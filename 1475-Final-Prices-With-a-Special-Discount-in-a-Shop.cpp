class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int>v;
        stack<int>s;
        s.push(0);     //for handling the edge case of not receiving the discount
        for(int i = prices.size()-1 ;i>=0;i--)
        {
            // remove all items from top of stack greater than current price
            while(s.size() > 0 && s.top() >prices[i])
            {
                    s.pop();
            }
            int t = prices[i] ;   

            prices[i] -= s.top() ;     // get discount 
            
            s.push(t) ;         // push current price
        }
        return prices;
    }
    
};
