class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        long long maxi=-1, stopping_ind=0;

        //sorting the vector
        sort(nums.begin(),nums.end());

        // initial sum is sum of first 2 elements of the vector
        long long sum=nums[0]+nums[1];
        int n=nums.size();


        //starting from the 2nd index (considering 0 based indexing)

        for(int i=2;i<n;i++){

            // if the calculated sum is greater than the next elememt, we update the maximum and and the stopping_index
            if(sum>nums[i]){
                maxi=max(maxi,sum);
                stopping_ind=i;
            }

            sum+=nums[i];

        }

        if(maxi!=-1)
        //adding stopping_index value if maxi!=-1
        maxi+=nums[stopping_ind];

        return maxi;
    }
};
