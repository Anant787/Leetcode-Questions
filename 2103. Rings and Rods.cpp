class Solution {
public:
    int countPoints(string rings) {
        int n = rings.size();

        //create a vector for rings 
        vector<bool>red(10,false);
        vector<bool>green(10,false);
        vector<bool>blue(10,false);

        int ringrod,count=0;
        //ringrod store the index of rod by subtracting from ASCCI value

        for(int i=0;i<n;i++)
        {
            ringrod = rings[i+1] - '0';

            if(rings[i] == 'R')
            {
                red[ringrod] = true;
            }
            if(rings[i] == 'G')
            {
                green[ringrod] = true;
            }
            if(rings[i] == 'B')
            {
                blue[ringrod] = true;
            }
        }

        for(int i=0;i<10;i++)
        {
            if(red[i]  && green[i]  && blue[i])      //if all found true,increase the count
            {
                count++;
            }
        }
        return count;
        
    }
};
