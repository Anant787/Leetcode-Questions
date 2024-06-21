#include <vector>
using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        
        // Calculate initially satisfied customers when grumpy is not active
        int initiallySatisfied = 0;
        for (int i = 0; i < n; ++i) {
            if (grumpy[i] == 0) {
                initiallySatisfied += customers[i];
            }
        }
        
        // Use sliding window to find the max additional satisfied customers by using the technique
        int maxAdditionalSatisfied = 0;
        int currentAdditionalSatisfied = 0;
        
        // Compute initial window of size 'minutes'
        for (int i = 0; i < minutes; ++i) {
            if (grumpy[i] == 1) {
                currentAdditionalSatisfied += customers[i];
            }
        }
        
        maxAdditionalSatisfied = currentAdditionalSatisfied;
        
        // Slide the window over the rest of the array
        for (int i = minutes; i < n; ++i) {
            if (grumpy[i] == 1) {
                currentAdditionalSatisfied += customers[i];
            }
            if (grumpy[i - minutes] == 1) {
                currentAdditionalSatisfied -= customers[i - minutes];
            }
            maxAdditionalSatisfied = max(maxAdditionalSatisfied, currentAdditionalSatisfied);
        }
        
        return initiallySatisfied + maxAdditionalSatisfied;
    }
};
