class Solution {
public:
  int minOperations(vector<int>& nums, int k) {
    // phase 1: xor all nums and k
    int xor_sum = k;
    for (int num: nums)
      xor_sum ^= num;
    
    // phrase 2: count the bit '1' of xor_sum
    int op_num = 0;     // store the result
    while (xor_sum > 0) {
      xor_sum &= (xor_sum - 1);   // remove the rightmost bit '1'
      ++op_num;
    }
    return op_num;
  }
};
