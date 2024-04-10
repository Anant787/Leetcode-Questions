class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {

        sort(deck.begin(),deck.end());
        
        int n=deck.size();
        
        vector<int> ans(n,0);
       
        queue<int> q;
        q.push(deck[n-1]);
        
        for(int i=n-2;i>=0;i--)
        {       
            int first=q.front(); // 17,      17,        13
            q.pop();             // [],      [13],      [17,11],
            q.push(first);       // [17],    [13,17],   [17,11,13]
            q.push(deck[i]);     // [17,13], [13,17,11],[17,11,13,7]
        }
        for(int i=n-1;i>=0;i--) // queue in reversed order is ans
        {
            ans[i]=q.front();
            q.pop();
        }
        return ans;
    }
};      
