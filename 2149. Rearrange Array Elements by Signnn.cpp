class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> v;
        vector<int> v1;
        vector<int> res;
        for(int i:nums){
            if(i>0)   v.push_back(i);
            else      v1.push_back(i);
        }
        for(int i=0;i<v.size();i++){
            res.push_back(v[i]);
            res.push_back(v1[i]);
        }
        return res;
    }
};
