//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;


string reverseWord(string str);


int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	string s;
	cin >> s;
	
	cout << reverseWord(s) << endl;
	}
	return 0;
	
}


// } Driver Code Ends


//User function Template for C++

// void reverse(string &str,int start,int end)
// {
//     while(start<end)
//     {
//         swap(str[start],str[end]);
//         start++;
//         end--;
//     }
// }

string reverseWord(string str){
    
    // int n = str.size();
    
    // reverse(str,0,n-1);
    
    // return str;
    int start = 0;
    int end = str.size()-1;
    
    while(start<end)
    {
        swap(str[start],str[end]);
        start++;
        end--;
    }
    return str;
    
}

