// class Solution {
// public:
//     string findDifferentBinaryString(vector<string>& nums) {
//         string ans = "";     // empty string
        
//         for (int i = 0; i < nums.size(); i++)
//         {
//             if (nums[i][i] == '1')
//                 ans += '0';
//             else
//                 ans += '1';
//         }

//         return ans;
//     }
// };
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans;

        int index = 0;
        for(auto binary : nums)
        {
            ans = ans + to_string('1' - binary[index]);
            index+=1;
        }
        return ans;
    }
};
