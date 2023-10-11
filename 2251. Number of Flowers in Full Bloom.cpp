class Solution {
public:
    int solve1(int arrival , vector<int> &s){
        //number of index with arrival time less than equal to arrival 
        int low = 0;
        int high = s.size()-1;
        int ind = 0;
        while(low <= high){
            int mid = (low+high)/2;
            if(s[mid] <= arrival){
                ind = mid+1;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ind;
    }
    int solve2(int arrival , vector<int> &e){
        //end time less than arrival 
        int low = 0;
        int high = e.size()-1;
        int ans = 0;
        while(low<=high){
            int mid = (low+high)/2;
            if(e[mid] < arrival){
                ans = mid+1;
                low = mid + 1;
            }
            else high=mid-1;
        }
        return ans;
    }
    vector<int> fullBloomFlowers(vector<vector<int>>& f, vector<int>& p) {
        int n = f.size();
        vector<int> s(n ,0) , e(n , 0);
        for(int i = 0;i<f.size();i++){
            s[i] = f[i][0];
            e[i] = f[i][1];
        }
        sort(s.begin() , s.end());
        sort(e.begin() , e.end());

        // Binary Search Approach 
        vector<int> ans;
        for(int i = 0;i<p.size();i++){
            int arr = p[i];

            int a = solve1(arr , s);
            int b = solve2(arr , e);
            if(a>0){
                ans.push_back(a-b);
            }else ans.push_back(0);
        }
        return ans;
    }
};
