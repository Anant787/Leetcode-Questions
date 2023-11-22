class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums){
        // N^2 space complexity 
        int n=nums.size();
        int m=n;
       
        for(int i=0;i<n;i++){ 
            int l=nums[i].size();
            m=max(l,m);
        }
        
        vector<vector<int>> temp(2*m);
         for(int i=n-1;i>=0;i--){
               int k=nums[i].size();
               for(int j=0;j<k;j++){
                 temp[i+j].push_back(nums[i][j]);
               }
         }
         
         int l=temp.size();
         vector<int> ans;
         
         for(int i=0;i<l;i++){
           for(auto it:temp[i]){
             ans.push_back(it);
             }
           }
        return ans;
    }
};

// HAsh map solution 

// class Solution {
// public:
//     vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        
//         int n = nums[0].size();
//         int m = nums.size();
        
//         map<int, vector<int> > mp;

//         for(int i = 0 ; i < m ; i++){int col=nums[i].size();
//             for(int j = 0 ; j < col ; j++){
                
//                 mp[i+j].push_back(nums[i][j]);
//             }
//         }
//         vector<int> v;
//         for(auto i : mp){
//             reverse(begin(i.second) , end(i.second));
//             for(auto it : i.second){
//                 v.push_back(it);
//             }
//             cout << endl;
        
//         }
//         return {v};
//     }
// };
