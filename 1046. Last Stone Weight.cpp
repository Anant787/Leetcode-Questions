class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>q;  //heap

        for(auto x : stones){
            q.push(x);
        }

        int s1,s2;

        while(q.size()>=2){
            s1 = q.top();
            q.pop();
            s2 = q.top();
            q.pop();
            q.push(abs(s1-s2));
        }

        return q.top();
        
    }
};
