class Solution {
    // Create two unordered maps to store the relationships between prime factors and their corresponding indices in the array
    unordered_map<int, vector<int>> mp1; // Stores indices corresponding to each prime factor
    unordered_map<int, vector<int>> mp2; // Stores prime factors corresponding to each index
    
public:
    void dfs(int index, vector<int>& idx, unordered_map<int,bool>& visited) {
        if(idx[index] == true) return; // If the index is already visited, return
        idx[index] = true; // Mark the current index as visited
        // Traverse through each prime factor associated with the current index
        for(auto &prime : mp2[index]) {
            if(visited[prime] == true) // If the prime factor is already visited, continue to the next iteration
                continue;
            visited[prime] = true; // Mark the prime factor as visited
            // Recursively traverse through the indices associated with the prime factor
            for(auto &index1 : mp1[prime]) {
                if(idx[index1] == true) continue; // If the index is already visited, continue to the next iteration
                dfs(index1, idx, visited); // Recursively call dfs for the unvisited index
            }
        }
    }
    
    // Function to check if it's possible to traverse all pairs of indices
    bool canTraverseAllPairs(vector<int>& nums) {
        // Populate the maps with the prime factors and their corresponding indices
        for (int i = 0; i < nums.size(); i++) {
            int temp = nums[i];
            // Iterate through potential prime factors of the current number
            for (int j = 2; j * j <= nums[i]; j++) {
                if (temp % j == 0) {
                    // If the current number is divisible by j, store the index and prime factor
                    mp1[j].push_back(i); // Add index to the prime factor's list of indices
                    mp2[i].push_back(j); // Add prime factor to the index's list of prime factors
                    while (temp % j == 0)
                        temp /= j;
                }
            }
            // If there's a prime factor greater than sqrt(num), store it as well
            if (temp > 1) {
                mp1[temp].push_back(i);
                mp2[i].push_back(temp);
            }
        }
        
        // Initialize variables for depth-first search
        vector<int> idx(nums.size(), 0); // Vector to track visited indices
        unordered_map<int, bool> visited; // Map to track visited prime factors
        
        // Perform depth-first search from index 0 to check connectivity
        dfs(0, idx, visited);
        
        // Check if all indices are visited
        for(int i = 0; i < idx.size(); i++) {
            if(idx[i] == false)
                return false; // If any index is unvisited, return false
        }
        return true; // All pairs of indices can be traversed
    }
};
