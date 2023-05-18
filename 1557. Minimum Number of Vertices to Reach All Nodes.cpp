class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {

        vector<int>indegree(n,0);  //indegree to mark the count the of each derived node

        for(int i=0;i<edges.size();i++)
        {
            indegree[edges[i][1]]++;
        }

        vector<int>ans;
        for(int i =0 ;i<n;i++)
        {
            if(indegree[i] == 0)  //count the node which have 0 indegree that our answer
            {
                ans.push_back(i);
            }
        }

        return ans;
        
    }
};
