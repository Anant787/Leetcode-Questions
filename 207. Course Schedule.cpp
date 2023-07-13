class Solution {
public:
    // DFS traversal

    bool dfs(vector<vector<int>> &graphs, vector<int> &visited, int i)
    {
        // 2 = conflict
        if (visited[i] == 2)
            return false;
        // 1 = visited
        if (visited[i] == 1)
            return true;

        visited[i] = 2;

        for (auto graph : graphs[i])
        {
            if (!dfs(graphs, visited, graph))
                return false;
        }
        visited[i] = 1;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> graphs(numCourses);
        vector<int> visited(numCourses);
        for (auto prerequisite : prerequisites)
            graphs[prerequisite[1]].push_back(prerequisite[0]);

        for (int i = 0; i < numCourses; i++)
        {
            if (!dfs(graphs, visited, i))
                return false;
        }
        return true;
    }
};
