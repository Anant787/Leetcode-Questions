class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int si=bloomDay.size();
        int ans=-1;
        int s=*min_element(bloomDay.begin(),bloomDay.end());
        int l=*max_element(bloomDay.begin(),bloomDay.end());
        while(s<=l){
                int count=0;
        int main=0;
        int mid=s+(l-s)/2;
        for(int i:bloomDay){
            if(i<=mid){
                count++;
            }
            else{
                main+=count/k;
                count=0;
            }
        }
        main+=count/k;
        if(main>=m){
            ans=mid;
            l=mid-1;
        }
        else{
            s=mid+1;
        }
        }
        return ans;
    }
};
