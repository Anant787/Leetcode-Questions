class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int count=0;
        while(left!=right){
            left = left >> 1;
            right = right >> 1;
            count++;
        }
        int res = left << count; //we can shift right as well
        return res;
    }
};
