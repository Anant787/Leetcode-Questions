class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
     // distinct and minimal. 
        vector<vector<int>> ans;

        int hash[202] = {0};
        int count = 0;
        for(int n: nums){         
            hash[n]++;
            if(hash[n] == 1){
                count++;
            }
        }
        while(count > 0){
            vector<int> temp;
            for(int i = 0; i < 202; i++){
               if(hash[i] > 0){
                   temp.push_back(i);
               } 
               hash[i]--;
               if(hash[i] == 0){
                   count--;
               }
            }
            ans.push_back(temp);
        }
        return ans;
    }

};
