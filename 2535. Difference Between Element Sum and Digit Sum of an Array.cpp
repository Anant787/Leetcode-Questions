class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int esum=0,dsum=0;
        int n = nums.size();

        for(int i=0;i<n;i++)
        {
            esum += nums[i];
        }

        cout<<esum<<endl;

        for(int i=0;i<n;i++)
        {
            string s = to_string(nums[i]);

            for(int j=0;j<s.size();j++)
            {
                dsum += (s[j] - '0');
            }
        }

        cout<<dsum<<" ";

        return abs(esum-dsum);


        // int esum=0,dsum=0;
        // int n = nums.size();
        // for(auto i : nums)
        // {
        //     esum+= i ;
        //     while(i)
        //     {
        //         int temp = i%10;
        //         dsum += temp;
        //         i = i/10;
        //     }
        // }
        // return abs(esum-dsum);


        
    }
};
