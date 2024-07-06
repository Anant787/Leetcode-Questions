class Solution {
public:
    int passThePillow(int n, int time) {
        int ans;
        int traverses;
        if(time<n){
            ans=time+1;
        }
        else{
            traverses=time/(n-1);  //no. of iterations the pillow undergoes
            time=time%(n-1);
            
            if(traverses%2==0){
                ans=time+1;
            }
            else{
                ans=n-time;
            }
        }
        return ans;
        
    }
};
