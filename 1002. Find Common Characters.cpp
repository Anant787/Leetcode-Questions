class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        
        map <char , vector<pair<string , int>>> mp;

        for( int i=0; i < words.size(); i++){
            string word = words[i];
            map < char, int > freq;

            for (int j=0; j < word.length(); j++){
                freq[word[j]]++;
            }

            for (const auto& [ch, count] : freq) {
                mp[ch].push_back({words[i], count});
            }
        }

        vector < string > ans;

        for ( auto& [ch , vec] : mp){
            if (vec.size() == words.size()){
                int minCount = INT_MAX;

                for ( auto& [word , cnt] : vec){
                    minCount = min (minCount ,cnt);
                }

                for(int i=0 ; i<minCount ; i++){
                    ans.push_back(string(1, ch));
                }
            }
        }

        return ans;
    }
};
