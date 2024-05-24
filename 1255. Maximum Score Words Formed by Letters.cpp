class Solution {
public:
    int solve(vector<string>& words, vector<int>& score,unordered_map<char,int>&mp,int i){
        if(i>=words.size()){
            return 0;
        }
        int include=0;
        int exclude=0;
        int flag=1;
        int score_word=0;
        unordered_map<char,int>temp;
        for(auto x:words[i]){
            if(mp[x]>0){
                score_word+=score[x-'a'];
                temp[x]++;
                mp[x]--;
            }else{
                flag=0;
            }
        }
        if(flag){
            include=score_word+solve(words,score,mp,i+1);
        }
        for(auto it:temp){
            mp[it.first]+=it.second;
        }
        exclude=0+solve(words,score,mp,i+1);
        return max(include,exclude);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        unordered_map<char,int>mp;
        for(auto x:letters){
            mp[x]++;
        }
        int ans=solve(words,score,mp,0);
        return ans;
    }
};
