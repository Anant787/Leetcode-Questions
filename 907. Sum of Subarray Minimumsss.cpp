class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
    int ans = 0;
    int mod = 1e9+7;
    vector<int> left(n) , right(n);
    stack<int> st;
    
    for(int i=0;i<n;i++)
    {
        while(!st.empty() && arr[st.top()] > arr[i])
            st.pop();
        if(st.size()>0)
            left[i] = i - st.top();
        else
            left[i] = i+1;
        st.push(i);
    }
    while(!st.empty())
        st.pop();
    
    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty() && arr[st.top()] >= arr[i])
            st.pop();
        if(st.size()>0)
            right[i] = st.top() - i;
        else
            right[i] = n-i;
        st.push(i);
    }
    
    for(int i=0;i<n;i++)
    {
        long long int prod = (left[i] * right[i])%mod;
        long long int num = (arr[i] * prod)%mod;
        ans = (ans + num)%mod;
    }
    return ans%mod;


    //     stack<int>s1,s2;
    //     int n = arr.size();
    //     vector<int>pre_smaller(n),next_smaller(n);

    //     for(int i=0;i<n;i++)
    //     {
    //         next_smaller[i] = n-i-1;
    //         pre_smaller[i] = i;
    //     }

    //     //for g2
    //     for(int i=0;i<n;i++)
    //     {
    //         while(!s1.empty()  && arr[s1.top()]>arr[i])
    //         {
    //             next_smaller[s1.top()] = i-s1.top()-1;
    //             s1.pop();
    //         }
    //         s1.push(i);
    //     }

    //     //for g1 case
    //     for(int i=n-1;i>=0;i--)
    //     {
    //         while(!s2.empty()  && arr[s2.top()]>=arr[i])
    //         {
    //             pre_smaller[s2.top()] = s2.top()-i-1;
    //             s2.pop();
    //         }
    //         s2.push(i);
    //     }

    //     long long int ans=0;
    //     int mod = 1e9+7;

    //     for(int i=0;i<n;i++)
    //     {
    //         ans += ( arr[i] * (pre_smaller[i] + 1) * (next_smaller[i] + 1));
    //         ans%=mod;
    //     }
    //     return ans;
     }
};
