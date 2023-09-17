class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
            // BFS and bit Masking
        if(graph.size()==1)
        return 0;
        queue<pair<int,int>>q;
        int finalState=(1<<graph.size())-1;
        map<pair<int,int>,int>m;
        for(int i=0;i<graph.size();i++)
        {
            q.push({i,(1<<i)});
            m[{i,(1<<i)}]=1;
        }
       
        int pathLength=0;
        while(!q.empty())
        {
            pathLength++;
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                auto top=q.front();
                q.pop();

                vector<int>temp=graph[top.first];
                for(int j=0;j<temp.size();j++)
                {
                    int newState=top.second|(1<<temp[j]);
                    if(m[{temp[j],newState}]==1)
                    continue;
                    if(newState==finalState)
                    return pathLength;
                    m[{temp[j],newState}]=1;
                    q.push({temp[j],newState});
                }
            }
        }
        return -1;
    }
};
