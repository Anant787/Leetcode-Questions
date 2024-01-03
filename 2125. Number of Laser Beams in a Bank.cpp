class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int m = bank.size(); // Number of rows in the bank
        int n = bank[0].length(); // Number of columns in the bank

        if (m == 1) {
            return 0; // If there's only one row, no lasers can be formed
        }

        int ans = 0; // Variable to store the total number of laser beams
        int prevCount = 0; // Variable to store the count of security devices in the previous row

        // Iterate through each row of the bank
        for (int i = 0; i < m; i++) {
            int currCount = count(bank[i].begin(), bank[i].end(), '1'); // Count the number of security devices in the current row

            if (currCount == 0) {
                continue; // If the current row has no security devices, skip to the next row
            }

            // Calculate the number of laser beams formed between the current row and the previous row
            ans += currCount * prevCount;

            // Update the count of security devices in the previous row for the next iteration
            prevCount = currCount;
        }

        return ans; // Return the total number of laser beams
    }
};
