class Solution {
public:
    long long wonderfulSubstrings(string word) {
        int cumxor = 0;
        vector<int> count(1024,0);
        count[0] = 1;
        long long result = 0;
        for(int i = 0; i < word.size(); i++){
            int shift = word[i] - 'a';
            cumxor = cumxor ^ (1<<shift); //(1<<shift) means binary rep

            result += count[cumxor]; //all even characters

            for(char ch = 'a'; ch <= 'j'; ch++){
                shift = ch - 'a';
                int checkxor = cumxor ^ (1<<shift);

                result += count[checkxor];
            }

            count[cumxor]++;
        }
        return result;
    }
};
