class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {

        int sum=0;

        vector<int> cnt(26,0);
        
        for(auto it:chars)
        {
            cnt[it-'a']++;
        }

        for(auto it:words)
        {
            if(it.size()>chars.size()){
                continue;
            }
                vector<int> temp=cnt;
              bool  flag=true;
            for(auto x:it){
                temp[x-'a']--;
                if(temp[x-'a']<0){
                    flag=false;
                    break;
                }


            }
            if(flag)sum+=it.size();
        }
        
        return sum;



        // int count=0;
        // for(int i=0;i<words.size();i++){
        //     unordered_map<char,int> mp;

        //     for(int j=0;j<chars.size();j++){
        //         mp[chars[j]]++;
        //     }
        //     int flag=0;
        //     for(int j=0;j<words[i].size();j++){
        //         if(mp.find(words[i][j])!=mp.end()){
        //             mp[words[i][j]]--;
        //             if(mp[words[i][j]]==0){
        //                 mp.erase(words[i][j]);
        //             }
        //         }else{
        //             flag=1;
        //         }
        //     }

        //     if(flag==0){
        //         count=count+words[i].size();
        //     }
            
        // }

        // return count;
    }
};
