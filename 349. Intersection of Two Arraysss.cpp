class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        unordered_set<int>s(nums1.begin(),nums1.end());   //set for unique element
        vector<int>v;     //vector for return ans

        for(int i=0;i<nums2.size();i++)
        {
            auto it = s.find(nums2[i]);        //if we find the element of nums2 in set

            if(it!=s.end())         //iterate till find it
            {
                v.push_back(nums2[i]);      //then push into the vector
                s.erase(it);             //remove the element from the set
            } 
        }
        return v;



    //     sort(nums1.begin(),nums2.end());
    //     sort(nums2.begin(),nums2.end());

    //     int n = nums1.size();
    //     int m = nums2.size();
    //     int i = 0 ,j=0;
    //    vector<int>v;
    //    set<int>si;

    //    while(i<n && j<m)
    //    {
    //        if(nums1[i]>nums2[j])
    //        {
    //            j++;
    //        }
    //        else if(nums1[i]<nums2[j])
    //        {
    //            i++;
    //        }
    //        else
    //        {
    //            si.insert(nums1[i]);
    //            i++;
    //            j++;
    //        }
    //    }

    //    for(auto i :si)
    //    {
    //        v.push_back(i);
    //    }
    //    return v;
       
    }
};
