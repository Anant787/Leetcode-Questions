class Solution {
    
    int getnums(char s)
    {
        switch(s)
        {
            case 'I':return 1;
            case 'V':return 5;
            case 'X':return 10;
            case 'L':return 50;
            case 'C':return 100;
            case 'D':return 500;
            case 'M':return 1000;   
            default:return 0;
        }
        return 0;
    }
public:
    int romanToInt(string s) {
        
        int sum=0;
        if(s.empty())
        {
            return 0;
        }
        for( int i=0;i<s.size()-1;i++)
        {
            if(getnums(s[i+1])>getnums(s[i]))
            {
                sum-=getnums(s[i]);
            }
            else{
                sum+=getnums(s[i]);
            }
        }        
        sum+=getnums(s[s.size()-1]);
        return sum;
        
            
        }
};