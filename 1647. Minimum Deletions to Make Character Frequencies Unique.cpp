class Solution {
public:
    int minDeletions(string s) {
        //basic navie approach 
        map<char,int>mp;      //map to store freq
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
        }

        set<int>st;    // use set DS to store the unique elements
        int ans=0;        // ans is used to store the answer

        for(auto it : mp)     // iterate over the map 
        {
            int freq = it.second;       //get the frequency

            while(freq>0 && st.find(freq) != st.end())  //check the case if freq is present in map or not
            { 
                freq--;       //if not === decrease the freq and again check for it
                ans++;              //and increase the count
            }

            st.insert(freq);  //if freq is not present in map..then it is unique freq...store in set DS

        }

        return ans;    //return the count of frequency
        

    }
};
