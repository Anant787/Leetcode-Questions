class Solution {
public:

    int maximalNetworkRank(int n, vector<vector<int>>& roads) {

        vector<vector<int>> adj (n, vector<int> (n, 0));
        vector<int> rank (n, 0);

        for(int i = 0; i < roads.size(); i++){
            adj[roads[i][0]][roads[i][1]] = 1;
            adj[roads[i][1]][roads[i][0]] = 1;
            rank[roads[i][1]]++;
            rank[roads[i][0]]++;
        }

        int maxNetRank = 0;

        int currPairRank = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i != j){
                    maxNetRank = max(maxNetRank, rank[i] + rank[j] - adj[i][j]);
                }
            }
        }

        return maxNetRank;
        
    }
};
