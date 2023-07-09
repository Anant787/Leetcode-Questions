class Solution {
public:
    //Sliding Window
    int solve(string s)
    {
        int n=s.size();
        int ans=0;
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                int l=0,h=0,cnt1=0,cnt2=0;
                if(i==j)continue;
                while(h<n){
                    if((s[h]-'a')==i){
                        cnt2++;
                    }
                     if((s[h]-'a')==j){
                        cnt1++;
                    }
                    while(l<n&&cnt1>cnt2){
                        if((s[l]-'a')==i){
                         cnt2--;
                         }
                         if((s[l]-'a')==j){
                            cnt1--;
                        } 
                        l++;
                    }
                    h++;
                    if(cnt1>0&&cnt2>0)
                    ans=max(ans,cnt2-cnt1);
                }
            }
        }
        return ans; 
    }  
      int largestVariance(string s) {
        string s1=s;
        reverse(s1.begin(),s1.end());
        return max(solve(s),solve(s1));
    }
};
