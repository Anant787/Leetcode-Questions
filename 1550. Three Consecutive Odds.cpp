class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        if(n<3){return false;}
        int i=0,j=1,k=2;
        while(k<n){
            if(arr[i]%2==1 &&arr[j]%2==1&&arr[k]%2==1){
                return true;
            }i++;j++;k++;
        }return false;
    }
};
