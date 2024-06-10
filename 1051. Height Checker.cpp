class Solution {
public:
    int heightChecker(vector<int>& heights) {
       vector<int>arr(heights.size(),0);
        for(int i=0;i<heights.size();i++){
            arr[i]=heights[i];
        }
        int ans=0;
        sort(arr.begin(),arr.end());
        for(int i=0;i<heights.size();i++){
            if(heights[i]!=arr[i]){
                ans++;
            }
        }
  return ans;      
    }
};
