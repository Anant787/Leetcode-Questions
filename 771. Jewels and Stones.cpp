class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        map<char,int>m;
        int count =0;

        for(int i=0;i<jewels.size();i++)  //map all the charcter of jewels string in map
        {
            m[jewels[i]] = 1;
        }

        for(int i=0;i<stones.size();i++)  //check all stones in jewels map  
        {
            if(m[stones[i]] == 1)
            {
                count++;   //increase the count if found
            }
        }
        return count;
    }
};
