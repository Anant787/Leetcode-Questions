class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<pair<int,char>> move;
        unordered_map<int,int> mpp;

        for(int i=0; i<n; i++){
            move.push_back({positions[i],directions[i]});
            mpp[positions[i]]=healths[i];
        }
        sort(move.begin(), move.end());

        stack<pair<int,char>> st;
        for(int i=0; i<n; i++){
            while(!st.empty() && st.top().second=='R' && move[i].second=='L'){
                if(mpp[move[i].first]>mpp[st.top().first]){
                    mpp[st.top().first]=0;
                    st.pop();
                    mpp[move[i].first]--;
                }
                else if(mpp[move[i].first]<mpp[st.top().first]){
                    mpp[st.top().first]--;
                    mpp[move[i].first]=0;
                    break;
                }
                else{
                    mpp[move[i].first]=0;
                    mpp[st.top().first]=0;
                    st.pop();
                    break;
                }
            }
            if(mpp[move[i].first]!=0) st.push(move[i]);
        }

        vector<int> ans;
        for(int i=0; i<n; i++){
            if(mpp[positions[i]]!=0){
                ans.push_back(mpp[positions[i]]);
            }
        }
        return ans;
    }
};
