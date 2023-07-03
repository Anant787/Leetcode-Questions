class Solution {
public:
    // using set
    bool buddyStrings(string A, string B) {
        int n =A.size();
        int m =B.size();
       // string str ="";

        if(n!=m)
        {
            return false;
        }
        if(A==B && set<char>(A.begin(),A.end()).size()<A.size()) 
        {
            return true;
        }

        vector<int>diff;
        for(int i=0;i<n;i++)
        {
            if(A[i]!=B[i])
            {
                diff.push_back(i);
            }
        }
        return (diff.size()==2  && A[diff[0]]==B[diff[1]] && A[diff[1]]==B[diff[0]]);
        
    }
};
