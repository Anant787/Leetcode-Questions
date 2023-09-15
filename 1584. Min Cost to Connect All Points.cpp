class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {

        int n=points.size();
        //min heap
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        pq.push({0,0});
        
        int count=0;
        vector<int>vis(n,0);
        
        while(pq.size()!=0)
        {
            pair<int,int>p=pq.top();
            pq.pop();
            int node=p.second;
            int wt=p.first;
            if(vis[node]==1)
                continue;
            vis[node]=1;
            count+=wt;
            for(int i=0;i<n;i++)
            {
                if(vis[i]==0)
                {
                    int x1=points[node][0];int y1=points[node][1];
                    int x2=points[i][0];int y2=points[i][1];
                    pq.push({abs(x2-x1)+abs(y2-y1),i});
                }
            }
        }
        return count;
    }
};
