class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        set<int>s;     //Hash set

        for(auto num : nums)       //insert the element in set
        {
            s.insert(num);
        }

        int longestcount = 0;       //for returing the longest consecutive sequence

        for(auto num : nums)  //iterative over the nums array
        {
            if(!s.count(num-1))  //check if the element which is smaller than the nums[i] is not present...bcz we count from the minimum element
            {
                int nextelement = num;  //mark that element and store
                int currentcount = 1;  //increase the current count of sequence 

                while(s.count(nextelement + 1))  //find the count of next element
                {
                    nextelement += 1;  //increase the element 
                    currentcount += 1;  //increase the count
                }

                longestcount = max(longestcount,currentcount);  //find the maximum count
            }
        }

        return longestcount;

        
    }
};
