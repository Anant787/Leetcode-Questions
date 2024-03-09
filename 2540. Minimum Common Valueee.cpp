class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

       // vector<int>v;
        int i=0,j=0;
        while(i<n && j<m)
        {
            if(nums1[i] > nums2[j])
            {
                j++;
            }
            else if(nums1[i]<nums2[j])
            {
                i++;
            }
            else
            {
                //v.push_back(nums1[i]);
                return nums1[i];
                i++;
                j++;
            }
        }
        // if(v.size()==0)
        return -1;
        //return v[0];
    }
};
