#define ll long long
class Solution {
public:
   
    long long maxRunTime(int n, vector<int>& bat) {
      ll sum = accumulate(bat.begin(),bat.end(),(ll)0);
      priority_queue<ll>q(bat.begin(),bat.end());
      while(q.top()>sum/n){
          sum -= q.top();q.pop();n--;
      }
      return sum/n;
    }
};
