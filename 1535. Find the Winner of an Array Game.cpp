class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n=arr.size();
        int count=0;
        int maxele=arr[0];
        int idx=1;
        while(count!=k){
            if(maxele>arr[idx]){
                if(count>n) return maxele;
                count++;
                arr.push_back(arr[idx]);
            }
            else{
                count=1;
                arr.push_back(maxele);
                maxele=arr[idx];
            }
            idx++;
        }
        return maxele;
    }
};
