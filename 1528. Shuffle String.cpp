class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string ans = s;        //temporary string 

        for(int i=0;i<s.size();i++)     //iterate over the string s
        {
            int temp = indices[i];        //get the index of element from indices
            ans[temp] = s[i];       //set on that position in temporary string
        }

        return ans;   //return the shuffle string
        
    }
};
