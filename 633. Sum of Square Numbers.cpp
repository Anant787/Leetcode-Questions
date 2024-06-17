class Solution {
public:
    bool judgeSquareSum(int c) {
        long low = 0;
        long high = sqrt(c);
        while(low <= high){
            if(low*low + high*high > c){
                high--;
            }
            else if(low*low + high*high < c){
                low++;
            }
            else{
                return true;
            }
        }
        return false;
    }
};
