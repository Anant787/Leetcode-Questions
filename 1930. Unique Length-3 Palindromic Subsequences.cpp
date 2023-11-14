class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<vector<int>>pairs(26,vector<int>(26,0));
        
        vector<int>left(26);
        vector<int>right(26);

        int n = s.size();
        int ans = 0;
        //insert left element
        left[s[0]-'a']++;
        
        //insert right element
        for(int i = 2;i<n;i++) right[s[i]-'a']++;
        
        //check for mid
        for(int i = 1;i<n-1;i++){
            for(int j = 0;j<26;j++){
                if(left[j] && right[j] && pairs[s[i]-'a'][j]==0){
                    ans++;
                    pairs[s[i]-'a'][j]=1;
                }
            }
            left[s[i]-'a']++;
            right[s[i+1]-'a']--;
        }
        
        return ans;
    }
};
