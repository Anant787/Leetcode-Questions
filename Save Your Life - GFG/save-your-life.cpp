//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
      string maxSum(string w,char x[], int b[],int n){
          unordered_map<char,int>mp;
          for(int i=0;i<n;i++)
          {
              mp[x[i]] = b[i];
          }
          
          int sum =0 ,maxi =INT_MIN;
          string ans = "",temp = "";
          
          for(int i=0;i<w.size();i++)
          {
              int ascii;
              
              if(mp.find(w[i]) != mp.end())
              {
                  ascii = mp[w[i]];
              }
              else
              {
                  ascii = (int)w[i];
              }
              
              sum+=ascii;
              temp += w[i];
              
              if(sum>maxi)
              {
                  maxi = sum;
                  ans = temp;
              }
              
              if(sum<0)
              {
                  sum =0;
                  temp = "";
              }
          }
          return ans;
      }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string w;
        cin>>w;
        int n;
        cin>>n;
        char x[n];
        int b[n];
        for(int i = 0;i<n;i++)
            cin>>x[i];
        for(int i = 0;i<n;i++)
            cin>>b[i];
        Solution ob;
        cout << ob.maxSum(w,x,b,n) << endl;
    }
    return 0; 
}
// } Driver Code Ends