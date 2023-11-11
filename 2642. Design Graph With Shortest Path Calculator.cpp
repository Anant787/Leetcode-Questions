class Graph {
public:
    vector<vector<pair<int,int>>> g;
    vector<long long int> dis;
    Graph(int n, vector<vector<int>>& edges) {
        g.resize(n);
        dis.resize(n, LLONG_MAX);
        for(auto ele:edges)
        {
            g[ele[0]].push_back({ele[1],ele[2]});
        }
    }
    void addEdge(vector<int> edge)
    {
        g[edge[0]].push_back({edge[1],edge[2]});
    }
    
    int dijsktra(int n1,int n2){
        priority_queue<pair<long long int,int>,vector<pair<long long int,int>>,greater<pair<long long int,int>>> pq;
        pq.push({0,n1});
        dis[n1] = 0;
        while(!pq.empty()){
            long long int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(node==n2) return d;

            for (auto ele : g[node]) {
                int neighbor = ele.first;
                int weight = ele.second;

                if (dis[node] + weight < dis[neighbor]) {
                    dis[neighbor] = dis[node] + weight;
                    pq.push({dis[neighbor], neighbor});
                }
            }
        }
        return -1;
    }

    int shortestPath(int node1, int node2) {
        dis.assign(dis.size(), LLONG_MAX);
        return dijsktra(node1,node2);
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
