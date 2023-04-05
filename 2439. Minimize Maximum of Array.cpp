class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long long mini = nums[0];

        long long sum =  nums[0];

        //balance the sum of array
        for (int i = 1; i<nums.size(); i++){
        
            sum += nums[i];
        
            if (nums[i] > mini){
        
                int avge = sum/(i+1);
        
                if (avge >= mini){
        
                    if (sum%(i+1))
        
                        mini = avge+1;
        
                    else
        
                        mini =avge;
                }
            }
        }
        return mini;
    }
};
