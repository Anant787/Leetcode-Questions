class Solution {
public:
    double average(vector<int>& salary) {

        //O(n)
        int n = salary.size();
        double total = 0;
        int maxi = INT_MIN;
        int mini = INT_MAX;

        for(int i=0;i<n;i++)
        {
            total += salary[i];

            mini = min(mini,salary[i]);
            maxi = max(maxi,salary[i]);
        }

        total -= (mini+maxi);

        return total / (n-2);
        

        //With sorting
        
        // sort(salary.begin(),salary.end());
    
        // double sum=0,avg;
        
        // int h=salary.size();
        // for(int i=1;i<=h-2;i++)
        //     {
        //         sum+=salary[i];
        //          avg=sum/(h-2);
        //     }
        // return avg;
    }
};
