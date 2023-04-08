class Solution {
public:
    bool squareIsWhite(string coordinates) {
        //accessing the first character and convert it into integer
        char ch = coordinates[0] -'a' + 1 ; 
        int a = ch ;
        // cout<<a ;
        string str = "" ;
        str += coordinates[1] ;   //access second character
        int b = stoi(str) ;

        if((a+b)%2==0){
            return false;
        }
        return true;
    }
};
