class Solution {
public:
    // static bool comp(int &a ,int &b)
    // {
    //     if(a % 2 == 0 && b % 2 == 1)
    //     {
    //         return true;
    //     }
    //     return false;
    // }
    vector<int> sortArrayByParity(vector<int>& nums) {

        // sort(nums.begin(),nums.end(),comp);       // by using comparator
        // return nums;

        // two Pointer Approach
        int pos = 0;
        for(int i =0;i<nums.size();i++)
        {
            if(nums[i]%2==0)
            {
                swap(nums[pos], nums[i]);
                pos++;
            }
        }
        return nums;

        //Naive Approach 
        // vector<int>even;
        // vector<int>odd;

        // vector<int>ans;

        // for(int i = 0;i<nums.size();i++)
        // {
        //     if(nums[i]% 2 == 0)
        //     {
        //         even.push_back(nums[i]);
        //     }
        //     else{
        //         odd.push_back(nums[i]);
        //     }
        // }
        // for(int i = 0 ; i<even.size();i++)
        // {
        //     ans.push_back(even[i]);
        // }
        // for(int i = 0 ; i<odd.size();i++)
        // {
        //     ans.push_back(odd[i]);
        // }
        // return ans;
        
    }
};
