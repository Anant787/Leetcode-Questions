class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        
        vector<pair<int,int>>v;                  //Pair
        
        priority_queue<int,vector<int>,greater<int>>pq;   //for min heap giveout minimum
        
        for(int i=0;i<n;i++)       //element push in pair of vector
        {
            v.push_back({efficiency[i],speed[i]}); 
        }
        
        long sum=0,ans=0; 
        
        sort(v.begin(),v.end());  //sort the vector according to efficiency
        
        for(int i=n-1;i>=0;i--)
        {
            sum+=v[i].second;        //total sum according to max sum
            pq.push(v[i].second);    // sum number is to be pushed into PQ
            
            if(pq.size()>k)         //only  need two engineers(k=2)
            {
                sum-=pq.top();     //if true then subtract the element form sum
                pq.pop();         //and Delete that element
            }
            
            ans=max(ans,sum*v[i].first);   // find max the performance by multiple by efficiency
        }
        
        
        return ans % 1000000007;      //for some input
        
    }
};