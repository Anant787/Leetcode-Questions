class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;  //map tp store the frequency count
        vector<int>res;  //to store the answer

        for(int i=0;i<nums.size();i++)  //insert the element into map with its freq.
        {
            mp[nums[i]]++;
        }

        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>>minh;  //min heap

        for(auto i = mp.begin() ; i!=mp.end() ; i++)
        {
            minh.push({i->second , i->first});   //condition check

            if(minh.size() > k)
            {
                minh.pop();
            }
        }

        while(minh.size() > 0)  
        {
            res.push_back(minh.top().second);
            minh.pop();
        }

        return res;
    }
};
