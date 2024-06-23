class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        
        int n = nums.size();
        //  pair<int, int >
        priority_queue< pair<int, int >> maxi;
        priority_queue< pair<int, int > , vector< pair<int, int >> ,greater< pair<int, int >> > mini;

        int i =0;
        int j = 0;

        int ans = 0;
         
         while( i < n){
            maxi.push({nums[i] , i});
             mini.push({nums[i] , i});

             if(maxi.top().first - mini.top().first > limit){

                if(maxi.top().second > mini.top().second){
                    // remove from min heap 
                    j = mini.top().second + 1;
                    while(!mini.empty() and mini.top().second < j) mini.pop();
                }
                else{
                    // remove from max heap 
                     j = maxi.top().second + 1;
                    while(!maxi.empty() and maxi.top().second < j) maxi.pop();
                }
                  
             }
             
             ans = max(ans , i-j+1);
             i++;
         }
        return ans;
    }
};
