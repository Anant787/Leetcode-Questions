class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        unordered_map<char, int> mp;
        for(int i=0 ;i<tasks.size() ;i++)
        mp[tasks[i]]++;

        priority_queue<int> pq;
        for(auto pa:mp)
            pq.push(pa.second);
        

        int ans = 0;
        while(!pq.empty()){
            int c = 0;
            vector<int> temp;

            while(c<=n &&!pq.empty()){
                int tp = pq.top();
                pq.pop();

                c++; ans++;

                if(tp-1>0)
                temp.push_back(tp-1);
            }

            for(int i=0 ;i<temp.size() ;i++)
            pq.push(temp[i]);

            if(pq.empty()) break;
            
            if(c<=n)
            ans += (n-c+1);
        }

        return ans;
    }
};
