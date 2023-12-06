
// class Solution {
// public:
//     int totalMoney(int n) {
//         int sum = 0;
//         int prev = 0;
//         int money = 1;
//         int i = 0;
//         int tmp = 1;

//         while(n)
//         {
//             if(i == 7)
//             {
//                 tmp++;
//                 money = tmp;
//                 i = 0;
//             }

//             sum += money;
//             money++;

//             i++;
//             n--;
//         }

//         return sum;
//     }
// };
class Solution {
public:
    int totalMoney(int n) 
    {
        int weeks = n/7, remainingDays = n%7;
        
        int totalMoney = (56 * weeks + 7 * weeks * (weeks - 1))/2;
        
        int weekNo = weeks + 1;
        
        totalMoney += remainingDays * ((weekNo + (weekNo + remainingDays - 1)))/2;

        return totalMoney;
    }
};
