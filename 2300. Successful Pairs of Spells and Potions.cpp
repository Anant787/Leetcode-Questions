class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int>ans;    //for storing the ans
        int p = potions.size();

        sort(potions.begin(),potions.end());  //sort the vector to apply Binary search

        for(long long i : spells)
        {
            int start = 0;
            int end = p-1;
            int count = 0;

            while(start<=end)
            {
                int mid = start + (end-start)/2;

                if(i * potions[mid] >= success)
                {
                    count += end - mid + 1;      //count the elements
                    end = mid-1;
                }
                else if(i * potions[mid] < success)
                {
                    start = mid+1;
                }
            }
            ans.push_back(count);   //push the count into vector ans
        }

        return ans;  //return ans
        
    }
};
