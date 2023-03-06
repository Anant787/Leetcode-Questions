class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n =arr.size();

        int start = 0 ,end = n;

        while(start<end)
        {
            int mid = (start + end)/2;
            //if element of mid is greater than the K after subtracting its index then shift the end value to mid

            if(arr[mid] - mid > k)
            {
               end = mid ;
            }
            else   //otherwise shift the start pointer
            {
                start = mid+1;
            }
        }
        return end + k ;   // ans in end pointer + the value of k (4+5 = 9)
        
    }
};
