class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int maxi = *max_element(groupSizes.begin(),groupSizes.end()); // for maximum element

        vector<vector<int>>ans;

        for(int i = 1 ;i<=maxi;i++)    //iterate upto max element
        {
            vector<int>subAns;
            for(int j = 0;j<groupSizes.size();j++)
            {
                if(groupSizes[j] == i)        // to group the elements
                {
                    if(subAns.size() >= i)    // if size is greater than 3,push into vector
                    {
                        ans.push_back(subAns);
                        subAns.clear();
                    }

                    subAns.push_back(j);
                }
            }
            if(subAns.size() != 0)
            {
                ans.push_back(subAns);
            }
        }
        return ans;
        
    }
};
