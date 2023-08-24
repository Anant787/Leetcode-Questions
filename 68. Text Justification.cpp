class Solution {
public:
    // Hard Problem 
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size(), i = 0;
        vector<string>ans;

        while(i<n){
            int cnt = 0;
            vector<string>temp;

            while(i<n && cnt+words[i].size()<=maxWidth){
                cnt+=words[i].size()+1;
                temp.push_back(words[i]);
                i++;
            }
            cnt-=temp.size();

            string curr;
            int j = 0;

            if(i == n){
                while(j<temp.size()){
                    curr+=temp[j];
                    if(j!=temp.size()-1)curr+=' ',cnt++;
                    j++;
                }
                int spaces = maxWidth-cnt;
                while(spaces--)curr+=' ';
                ans.push_back(curr);
                break;
            }

            int totalWords = temp.size(), spaceLeft = maxWidth-cnt;
            int spaces = 0;
            if(totalWords>1)spaces = (spaceLeft+totalWords-2)/(totalWords-1);

            while(j<temp.size()){
                curr+=temp[j++];
                int k = spaces;
                if(spaceLeft)while(k>0)curr+=' ',k--;
                spaceLeft-=spaces;
                totalWords--;
                if(totalWords>1)spaces = (spaceLeft+totalWords-2)/(totalWords-1);
            }
            while(spaceLeft>0)curr+=' ',spaceLeft--;

            ans.push_back(curr);
        }

        return ans;
    }
};
