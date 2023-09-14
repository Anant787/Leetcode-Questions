class Solution {
private:
    // DFS Traversal
    void dfs(string from){
        auto &it = mp[from];
        while(!it.empty()){
            string s = it.top();
            it.pop();
            dfs(s);
        }
        ans.push_back(from);
    }
public:
    //Global declare
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> mp;
    vector<string> ans;
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // for loop is used to coordinate the key value of tickets
        for(auto it : tickets)
            mp[it[0]].push(it[1]);

        dfs("JFK");

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
