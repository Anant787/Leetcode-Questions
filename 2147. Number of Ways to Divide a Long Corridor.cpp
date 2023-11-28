class Solution {
private:
    int MOD = 1e9+7;       // mod

public:
    int numberOfWays(string corridor) {
        int n = corridor.length();    // length of corridor string

        int ans = 1;    // will store answer, initialized to 1, assuming we will have atleast 1 solution

        int seats = 0;  // will store the count of seats

        int i = 0;  // will store the position
        while(i < n)
        {
            // incrementing string
            if(corridor[i] == 'S')
                seats++;

            i++;

            // if found atleast 2 seats which can be grouped in pair
            if(seats > 0 && seats % 2 == 0)
            {
                // counting the number of Pots/flowers present between 2 pair of seats
                int streak = 0;
                while(i < n && corridor[i] != 'S')
                {
                    streak++;
                    i++;
                }

                // Addition of ways to make divider, only when we have some seats after current seat, not reached end of string
                if(i < n)
                    ans = (1LL * ans * (streak + 1)) % MOD;
            }
        }

        // if the there is no seat in the string OR number of seats is ODD (cant group in 2 seats each) answer is '0'
        if(seats == 0 || seats % 2 != 0)
            return 0;

        return ans;
    }
};
