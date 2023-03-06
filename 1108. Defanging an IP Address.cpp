class Solution {
public:
    string defangIPaddr(string address) {
        
        int i=0;
        while(i<address.length())
        {
            if(address[i] == '.')
            {
               address.insert(i,"[");
               i+=2;
               address.insert(i,"]");
            }
            i++;
        }
        return address;

        //string s;
        // for(int i =0;i<address.size();i++)
        // {
        //     if(address[i] == '.')
        //     {
        //         s.push_back('[');
        //         s.push_back('.');
        //         s.push_back(']');
        //     }
        //     else
        //     {
        //         s+=address[i];
        //     }
        // }
        // return s;        
    }
};
