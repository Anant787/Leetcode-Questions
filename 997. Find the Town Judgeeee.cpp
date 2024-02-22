class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // Initialize indeg and outdeg vectors with size n+1 and set all elements to 0
       vector<int> indeg(n+1, 0), outdeg(n+1, 0);
       
       // Iterate through the trust relationships and increment the indeg and outdeg of the corresponding people
       for(auto it : trust){
           indeg[it[1]]++;
           outdeg[it[0]]++;
       }
       
       // Iterate through the indeg vector
       for(int i=1;i<=n;i++)
           // Check if a person has n-1 incoming trusts and 0 outgoing trusts
           if(indeg[i]==n-1 && outdeg[i]==0)
                return i;
       
       // If no such person found, return -1
       return -1;
    }
};
