class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //Moore Voting Algo

        int el;
        int count=0;

        for(int i=0;i<nums.size();i++)
        {
            if(count==0)
            {
                count=1;
                el = nums[i];
            }
            else if(nums[i] == el)
            {
                count++;
            }
            else
            {
                count--;
            }
        }

        int count1 = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == el)
            {
                count1++;
            }
        }
        if(count1 > (nums.size() / 2))
        {
            return el;
        }

        return -1;
        
        //Simple naive wise approach
       // sort(nums.begin(),nums.end()); 
        // int count=0;
        // int temp;
        
        // for(int i = 0;i<nums.size();i++)
        // {
        //     if(count)
        //     {
        //         count+=(nums[i]==temp?1:-1);
        //     }
        //     else
        //     {
        //         temp = nums[i];
        //         count = 1 ;
        //     }
        // }
        // return temp;
    }
};
