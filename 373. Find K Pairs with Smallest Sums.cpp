// class Triplet{
//     public:
//     int val, ind1, ind2;

//     Triplet(int val, int ind1, int ind2){
//         this->val = val;
//         this->ind1 = ind1;
//         this->ind2 = ind2;
//     }
// };

// class myCmp{
//     public:
//     bool operator()(Triplet& a, Triplet& b){
//         return a.val > b.val;
//     }
// };

// class Solution {
// public:
//     vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
//         priority_queue<Triplet, vector<Triplet>, myCmp> pq;

//         for(int i=0;i<nums1.size();i++){
//             Triplet t(nums1[i]+nums2[0],i,1);
//             pq.push(t);
//         }

//         vector<vector<int>> ans;
//         while(k-- and !pq.empty()){
//             Triplet t = pq.top();
//             pq.pop();

//             ans.push_back({nums1[t.ind1],nums2[t.ind2-1]});
//             if(t.ind2 < nums2.size()){
//                 Triplet y(nums1[t.ind1]+nums2[t.ind2],t.ind1,t.ind2+1);
//                 pq.push(y);
//             }
//         }

//         return ans;
//     }
// };




class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int,pair<int,int>>> pq;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                int sum=nums1[i]+nums2[j];
                if(pq.size()<k) pq.push({sum,{nums1[i],nums2[j]}});
                else if(sum<pq.top().first){
                    pq.pop();
                    pq.push({sum,{nums1[i],nums2[j]}});
                } else break;
            }
        }
        while(!pq.empty()){
            ans.push_back({pq.top().second.first,pq.top().second.second});
            pq.pop();
        }
        return ans;
    }
};
