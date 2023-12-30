class Solution
{
public:
    bool makeEqual(vector<string> &words)
    {
        int n = words.size();

        vector<int> charCount(26, 0);      // vector to store the alpha

        for (int ind = 0; ind < n; ind++)
        {
            for (char &ch : words[ind])
            {
                int index = ch - 'a';
                
                charCount[index]++;
            }
        }

        for (int ind = 0; ind < 26; ind++)
        {
            int count = charCount[ind];

            if (count % n != 0)
            {
                return false;
            }
        }

        return true;
    }
};
