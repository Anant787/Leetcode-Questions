class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        //Striver approach hai

        vector<int>ans;
        deque<int>dq;

        for(int i=0;i<nums.size();i++)
        {
            if(!dq.empty()  && dq.front() == i-k)  //out of bound case
            {
                dq.pop_front();
            }
            while(!dq.empty() && nums[dq.back()] < nums[i])    //check form the right side
            {
                dq.pop_back();
            }

            dq.push_back(i);

            if(i>=k-1)
            {
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;

        //Aditya verma's Approach

        // int n = nums.size();
        // int i=0,j=0;
        // deque<int>dq;     //list to store the maximum element for each window and also remove smaller element from front

        // vector<int>ans;  //to store the ans

        // while(j<n)
        // {
        //     while(dq.size() > 0 && dq.back() < nums[j])  //managing the maximum element
        //     {
        //         dq.pop_back();
        //     }

        //     dq.push_back(nums[j]);

        //     if(j-i+1 < k)   //case to iterate upto K size
        //     {
        //         j++;
        //     }

        //     else if(j-i+1 == k)     
        //     {
        //         ans.push_back(dq.front());
        //         if(dq.front() == nums[i])
        //         {
        //             dq.pop_front();
        //         }
        //         i++;
        //         j++;
        //     }
        // }
        // return ans;

        
    }
};
