class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> graph(n + 1);
        vector<int> indegree(n + 1, 0);
        
        // Create an adjacency list and calculate indegrees for each course.
        for (const auto& relation : relations) {
            int prevCourse = relation[0];
            int nextCourse = relation[1];
            graph[prevCourse].push_back(nextCourse);
            indegree[nextCourse]++;
        }
        
        queue<int> q; // queue
        vector<int> earliestStart(n + 1, 0);
        
        // Add all courses with no prerequisites to the queue.
        for (int i = 1; i <= n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                earliestStart[i] = 0;
            }
        }
        
        int minTime = 0;
        
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            
            // Update the minimum time needed to complete this course.
            minTime = max(minTime, earliestStart[course] + time[course - 1]);
            
            // Process the courses that depend on the current course.
            for (int nextCourse : graph[course]) {
                indegree[nextCourse]--;
                // Update the earliest start time for the next course.
                earliestStart[nextCourse] = max(earliestStart[nextCourse], earliestStart[course] + time[course - 1]);
                
                if (indegree[nextCourse] == 0) {
                    q.push(nextCourse);
                }
            }
        }
        
        return minTime;
    }
};
