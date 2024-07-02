class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        
        vector<int>res;
        
        int n=nums1.size();
        int m= nums2.size();
        
        int i=0,j=0;
        
        while(i<n && j<m)
        {
            if(nums1[i]>nums2[j])
            {
                j++;
            }
            else if(nums1[i]<nums2[j])
            {
                    i++;
                
            }
            else{
                res.push_back(nums1[i]);

            i++;
            j++;    
                }
        }
        return res;
        
       

        
//         for(int i=0;i<=nums1.size();i++)
//         {
//             for(int j=0;j<nums2.size();j++)
//             {
//                 if(nums1[i]==nums2[j])
//                 {
//                     res.push_back(i);
//                    // res.push_back(j);

//                 }
//             }
//         }
//         return res;
        
    }
};
