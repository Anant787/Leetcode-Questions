class Solution {
public:
    int addDigits(int num) {
        //int sum=0;
        int res;

        if(num>=0  && num<=9)
        {
            return num;
        }
        else
        {
            while(num>9)     //calculate the sum Repeated
            {
                res=num%10;
                num = num/10;
                res += num;
                num =res;
            }
        }
        return res;
        
    }
};
