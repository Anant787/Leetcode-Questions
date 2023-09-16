int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[0][0] = 0;

        priority_queue<pair<int,pair<int,int>>> pq;
        pq.push({0,{0,0}});

        while(!pq.empty()){
            int curr_diff = -pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            if(x==n-1 && y==m-1) return curr_diff;

            for(int i=0; i<4; i++){
                int newx = x + dx[i];
                int newy = y + dy[i];

                if(newx >= 0 && newy >= 0 && newx < n && newy < m){
                    int new_diff = max(abs(heights[x][y] - heights[newx][newy]),curr_diff);

                    if(new_diff < dist[newx][newy]){
                        dist[newx][newy] = new_diff;
                        pq.push({-new_diff,{newx,newy}});
                    }

                }
            }
        }

        return 0;
    }
};
