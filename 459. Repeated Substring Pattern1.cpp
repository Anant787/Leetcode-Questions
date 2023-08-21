class Solution {
public:
    // 2 solution
    bool repeatedSubstringPattern(string s)
{
    int n = s.length();
    string str = "";

    for (int i = 0; i < n - 1; i++)
    {
        str += s[i];
        int l = str.length();

        if (n % l == 0)
        {
            int times = n / l;
            string matching = "";

            while (times--)
                matching += str;

            if (matching == s)
                return true;
        }
    }
    return false;
}
};
