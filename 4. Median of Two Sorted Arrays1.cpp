class Solution {
public:
    double findMedianSortedArrays(vector<int>& v1, vector<int>& v2) {

        //TWO Pointe approach
        
        // int n1= v1.size() , n2 = v2.size() ;
        // if(n1>n2){
        //     return findMedianSortedArrays(v2,v1) ;
        // }
        // int i = 0 , j = 0 , count = 0 ;
        // int med_ind = (n1+n2+1)/2 -1 ;
        // while(i<n1 && j<n2 && count!=med_ind){
        //     if(v1[i]<=v2[j]){
        //         i++ ;
        //         count ++ ;
        //     }
        //     else{
        //         j++ ;
        //         count++ ;
        //     }
        // }
        // if((n1+n2)%2!=0){
        //     return min(v1[i],v2[j]) ; 
        // }
        // else{
        //     return (v1[i]+max(v1[i],v2[j]))/2.0 ;
        // }

        // return 0.0;



        //Binary search approach

        int n1 = v1.size();
        int n2 = v2.size();

        if(n1>n2)
        {
            return findMedianSortedArrays(v2,v1);
        }

        int low=0,high = n1;

        while(low<=high)
        {
            int cut1 = (low+high)/2;
            int cut2 = (n1+n2+1)/2 - cut1;

            double l1 = cut1 == 0 ? INT_MIN : v1[cut1-1];
            double l2 = cut2 == 0 ? INT_MIN : v2[cut2-1];

            double r1 = cut1 == n1 ? INT_MAX : v1[cut1];
            double r2 = cut2 == n2 ? INT_MAX : v2[cut2];

            if(l1<=r2  && l2<=r1)
            {
                if((n1 + n2) & 1)    //for odd
                {
                    return max(l1,l2);
                }
                else
                {
                    return (max(l1,l2) + min(r1,r2)) / 2.0;
                }
            }
            else if(l1>r2)
            {
                high = cut1-1;
            }
            else
            {
                low = cut1+1;
            }
        }
        return 0.0;
    }
};
