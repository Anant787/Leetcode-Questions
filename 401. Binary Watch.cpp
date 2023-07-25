class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
       vector<string> ans;
    for(int hr=0; hr<=11; ++hr){
        for(int min=0; min<=59; ++min){
            if(__builtin_popcount(hr)+__builtin_popcount(min)==turnedOn){
                string hour=to_string(hr);
                string minutes="";
                if(min<=9){
                    minutes+='0';
                }
                minutes+=to_string(min);
                ans.push_back(hour+":"+minutes);
            }
        }
    }
    return ans; 
    }
};
