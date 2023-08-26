// class Solution {
// public:
//     int findLongestChain(vector<vector<int>>& pairs) {
//         sort(pairs.begin(),pairs.end());

//         int n = pairs.size() , ct = 1 , end = pairs[0][1];
//         for(int i=1;i<n;i++)
//         {
//             if(end < pairs[i][0])
//             {
//                 ct++;
//                 end = pairs[i][1];
//             }
//             else end = min(pairs[i][1],end);
//         }

//         return ct;
//     }
// };

class Solution {
public:

    // Same Approach but different code
static bool cmp(vector<int>&v1,vector<int>&v2){
        return v1[1]<v2[1];
        
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),cmp);
        int result=1;
        int update=pairs[0][1];
        for(int i=1;i<pairs.size();i++){
            if(update<pairs[i][0]){
                result++;
                update=pairs[i][1];
            }
        }
        return result;
    }
};
