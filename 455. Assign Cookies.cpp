class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // O(nlogn)
        int res = 0;

        if (s.size() == 0 && g.size()) return res;
        // sort the vectors
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0; // Children vector iterator
        int j = 0; // Cookie vector iterator
        while ( i < g.size() && j < s.size()) {
            if (s[j] >= g[i]) { // Checking if cookie can satisfy the child
                res++;
                i++;
                j++;
            } else j++;
        }

        return res;
    }
};
