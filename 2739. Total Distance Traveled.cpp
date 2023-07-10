class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int distance = 0; //total distance travelled
        int litreConsumed = 0; //how many litres consumed from main tank
        while(mainTank){
            distance += 10;
            mainTank--;
            litreConsumed++;
            if(litreConsumed == 5 && additionalTank > 0){
                additionalTank--;
                mainTank++;
                litreConsumed = 0;
            }
        }
        return distance; 
        
    }
};
