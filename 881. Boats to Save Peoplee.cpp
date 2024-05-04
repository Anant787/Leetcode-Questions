class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int count = 0;  //count the minimum boats

        sort(people.begin(),people.end());  //sort the people array for BS

        int left=0;
        int right = people.size()-1;

        while(left<=right)
        {
            int sum = people[left] + people[right];

            if(sum<=limit)  //check for the limits
            {
                count++;
                left++;
                right--;
            }
            else
            {
                count++;
                right--;
            }
        }
        return count;
    }
};
