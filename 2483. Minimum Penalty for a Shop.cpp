class Solution {
public:
    // String
    int bestClosingTime(string c) {
        
        int s = c.size(); // Get the size of the input string

        int y = 0; // Initialize count of 'Y' occurrences
        
        // Iterate through the input string to count the occurrences of 'Y'
        for (int i = 0; i < s; i++) {
            if (c[i] == 'Y')
                y++; // Increment 'Y' count if the current character is 'Y'
        }

        int sum = INT_MAX; // Initialize a variable to store the minimum sum
        int ans; // Initialize a variable to store the index with the best closing time

        int curr_Y = 0; // Initialize current 'Y' count
        int curr_N = 0; // Initialize current 'N' count
        
        // Iterate through the input string and calculate the minimum sum of 'Y' and 'N' counts
        for (int i = 0; i <= s; i++) {
            int total = y - curr_Y + curr_N; // Calculate the total count for the current index
            
            if (total < sum) {
                sum = total; // Update the minimum sum if a smaller sum is found
                ans = i; // Update the best closing time index
            }

            if (i != s && c[i] == 'Y')
                curr_Y++; // Update the current 'Y' count if the current character is 'Y'
            else if (i != s && c[i] == 'N')
                curr_N++; // Update the current 'N' count if the current character is 'N'
        }

        return ans; // Return the index with the best closing time
    }
};

//if you find it helpful please vote
