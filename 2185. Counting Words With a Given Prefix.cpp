class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {

        int n = words.size();
        int m = pref.size();

        unordered_set<string>s;   //store the unique words
        int count=0;  //to store the answer

        s.insert(pref);

        for(int i=0;i<n;i++)
        {
            if(words[i].size() < m)   //edge case
            {
                continue;
            }
            if(s.count(words[i].substr(0,m)))  //check for prefix
            {
                count++; //increase the count
            }
        }
        return count++;

        
    }
};
