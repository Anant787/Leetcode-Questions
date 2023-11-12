class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int,vector<int>> mp;

        for(int i=0;i<routes.size();i++)
        {
            for(int j=0;j<routes[i].size();j++)
            {
                mp[routes[i][j]].push_back(i);
            }
        }
        queue<pair<int,int>> q;

        q.push({source,0});
        
        unordered_set<int> st;
        st.insert(source);
        
        while(!q.empty()){
            auto it = q.front();
            int a = it.first , cnt = it.second;
            q.pop();
            if(a == target){
                return cnt;
            }
            for(auto it:mp[a]){
                for(auto it1:routes[it]){
                    if(!st.count(it1)){
                        st.insert(it1);
                        q.push({it1,cnt+1});
                    }
                } 
                routes[it].clear();   
            }
        }
        return -1;
    }
};
