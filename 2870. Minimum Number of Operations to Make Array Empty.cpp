class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> umap;

        for(int i=0;i<nums.size();i++){
            umap[nums[i]]++;
        }

        int count = 0;

        for(auto x:umap){
            if(x.second == 1){
                return -1;
            }

            if(x.second % 3 == 1){
                count+= (x.second/3 + 1);
            }

            if(x.second % 3 == 2){
                count+= (x.second/3 + 1);
            }

            if(x.second % 3 == 0){
                count+= x.second/3;
            }
        }

        return count;
    }
};
