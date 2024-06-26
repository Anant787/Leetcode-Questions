class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n = version1.length();
        int m = version2.length();
        int i =0,j=0;

        while(i < n || j < m){
            int value1 =0, value2=0;
            while((i < n) && (version1[i] != '.')){
                value1 = value1 * 10 + (version1[i] - '0');
                i++;
            }
            while((j < m) && (version2[j] != '.')){
                value2 = value2 * 10 + (version2[j] - '0');
                j++;
            }

            if(value1 <  value2) return -1;
            else if(value1 > value2) return 1;
            i++,j++;
        }
        return 0;
    }
};
