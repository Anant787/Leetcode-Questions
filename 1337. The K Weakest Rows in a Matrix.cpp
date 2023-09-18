class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int row = mat.size();
        int col = mat[0].size();
        int count = 0;
        // Minh Heap Approach
        priority_queue<pair<int,int>,vector<pair<int,int>> , greater<pair<int,int>> > minh;

        for(int i=0;i<row;i++)
        {
            count = 0;            // count 0 for every new row
            for(int j= 0; j<col;j++)
            {
                if(mat[i][j] == 1)
                {
                    count++;
                }
            }
            minh.push({count,i});           // insert the count ans its index in min heap
        }

        vector<int>ans;      // vector to store the ans

        for(int i =0 ;i<k;i++)     // top k element is our ans
        {
            ans.push_back(minh.top().second);
            minh.pop();
        }

        return ans;


        // Max Heap Approach
        // unordered_map<int,int>mp;
        
        // for(int i =0 ;i<row ; i++)
        // {
        //     count = 0 ;
        //     for(int j =0 ; j<col ; j++)
        //     {
        //         if(mat[i][j] == 1)
        //         {
        //             count++;
        //         }
        //         mp[i] = count;
        //     }
        // }

        // priority_queue<pair<int,int>>pq;

        // for(int i = 0 ;i<mp.size();i++)
        // {
        //     pq.push({mp[i],i});

        //     if(pq.size() > k)
        //     {
        //         pq.pop();
        //     }
        // }

        // vector<int>ans;
        // while(pq.size()>0){
        //     ans.push_back(pq.top().second);
        //     pq.pop();
        // }
        // reverse(ans.begin(),ans.end());

        // return ans;

        
    }
};
