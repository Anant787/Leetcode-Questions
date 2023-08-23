class Solution {
public:
    //Using MaX heap
    string reorganizeString(string s) {
        int n=s.length();
        string result="";
        vector<int> frequ(26,0);

        for(char &ch : s)
        {
            frequ[ch-'a']++;
            if(frequ[ch-'a'] > (n+1)/2)
            {
                return "";
            }
        }

        priority_queue<pair<int,char>,vector<pair<int,char>>> pq;
        
        for(char ch='a';ch<='z';ch++)
        {
            if(frequ[ch-'a']>0)
            {
                pq.push({frequ[ch-'a'],ch});
            }
        }
        
        while(pq.size()>=2)
        {
            auto p1=pq.top();
            pq.pop();
            auto p2=pq.top();
            pq.pop();
            result+=p1.second; p1.first--;
            result+=p2.second; p2.first--;
            if(p1.first >0)
            {
                pq.push(p1);
            }
            if(p2.first > 0)
            {
                pq.push(p2);
            }
        }
       
        if(!pq.empty())
        {
            result+=pq.top().second;
        }
        
        return result;
    }
};
