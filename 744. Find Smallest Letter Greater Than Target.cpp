class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {

        //declaring ans as first character of letters array to deal with the case when character does not exist
        char ans = letters[0];

        int n = letters.size();
        int low = 0;
        int high = n - 1;

        //Binary Search
        while (low <= high) {

            int mid = low + (high - low) / 2;

            //if condition satisfies
            if (letters[mid] > target) {

                //probable answer
                ans = letters[mid];
                //look for better answer on left
                high = mid - 1;
            }
            
            //search in the right half 
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
