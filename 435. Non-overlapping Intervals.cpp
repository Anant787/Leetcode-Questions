class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size() ; 
        sort(intervals.begin() , intervals.end() ) ; 
        int ans = 0 , preEnd = intervals[0][1] , curStart  ; 
        for(int i=1; i<n; i++)
        {
            curStart = intervals[i][0] ; 
            if(preEnd<=curStart)
            {
                preEnd = intervals[i][1] ;
            }
            else
            {
                preEnd = min(preEnd , intervals[i][1] ) ;
                ans++ ;
            } 
        }
        return ans ;
        
    }
};
