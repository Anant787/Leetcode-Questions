class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int n = nums.size();
        //simple and clean 
        int preSum = 0;
        int minVal = 0;

        for(int i =0;i<n;i++)
        {
            preSum += nums[i];
            minVal = min(minVal , preSum);
        }

        return abs(minVal) + 1;


        //Basic Approach 
        // int startValue = 1;
        // int j=0;

        // int sum=startValue;
        // while(j<=nums.size()-1)
        // {
        //     sum +=nums[j];
        //     j++;

        //     if(sum<0)
        //     {
        //         startValue +=(-sum+1);
        //         sum = sum+(-sum+1);
        //     }
        //     else if(sum==0)
        //     {
        //         startValue++;
        //         sum++;
        //     }
        // }

        // return startValue;


        
    }
};
