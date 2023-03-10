class Solution {
public:
    int countAsterisks(string s) {
        bool isActive = false;      //flag variable to check the bound condition
        int count=0;   //count the *

        for(int i=0;i<s.size();i++)
        {
            //if the string get * not in between the pairs,increase the count
            if(s[i] == '*' && isActive == false)   
            {
                count++;
            }
            if(s[i] == '|')    //again initialize for boundary condition
            {
                isActive = !isActive;
            }
        }
        return count;
    }
};
