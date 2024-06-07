class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        map<string,bool> m;
        for(int i=0;i<dictionary.size();i++){
            m[dictionary[i]] = true;
        }

        string ans = "";
        int i = 0;
        while(i < sentence.length()){
            string temp ="";
            while(i<sentence.length() && sentence[i] != ' '){
                temp += sentence[i];
                if(m[temp] == true) break;
                i++;
            }
            while(i<sentence.length() && sentence[i] !=' ') i++;
            ans += temp;
            if(i<sentence.length()) ans += " ";
            i++;
        }
        return ans;
    }
};
