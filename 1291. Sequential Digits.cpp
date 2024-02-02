class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        string s = "123456789";
        string l = to_string(low), h = to_string(high);

        int n=l.size(),m=h.size();

        for(int i=n;i<=m;i++){
            for(int j=0;j<=9-i;j++){
                string temp = s.substr(j,i);
                int curr = stoi(temp);
                if(curr>=low && curr<=high) ans.push_back(curr);
            }
        }
        return ans;
    }
};
