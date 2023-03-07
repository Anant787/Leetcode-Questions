typedef long long ll;
class Solution {
public:
    bool check(vector<int>&time,ll mid , ll totalTrips)
    {
        ll trips = 0;
        for(auto &i : time)
        {
            trips += (mid/i);

            if(trips >= totalTrips)
            {
                return true;
            }
        }
        return false;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n = time.size();

        sort(time.begin(),time.end());

        ll low = (ll)time[0];
        ll high = (ll)time[n-1] * (ll)totalTrips ;

        while(low<high)
        {
            ll mid = low + (high-low)/2;

            if(check(time,mid,(ll)totalTrips))
            {
                high = mid;
            }
            else
            {
                low = mid+1;
            }
        }
        return low;
        
    }
};
