class Solution {
public:
    int Mod = 1e9+7;    // for modulas
    int countOrders(int n) {
        long places = 2*n;      // for n places : n for pickup and n for dilveries
        long seq =1;
        for(int i = n;i>=1;i--)
        {
            seq = (seq * ((places * ( places-1 ))) / 2 )% Mod ;
            places = places-2;  
        }
        return (int)seq;
        
    }
};
