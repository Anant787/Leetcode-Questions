class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        sort(hand.begin(), hand.end());
        unordered_map<int, int> umap;
        for(int i = 0; i < hand.size(); i++){
            umap[hand[i]]++;
        }
        for(int i = 0; i < hand.size(); i++){
            int cur = hand[i];
            int cur_freq = umap[cur];
            if(cur_freq == 0){
                continue;
            }
            for(int j = 0; j < groupSize; j++){
                int loc = cur + j;
                if(umap.find(loc) == umap.end()){
                    return false;
                }
                if(umap[loc] < cur_freq){
                    return false;
                }
                umap[loc] = umap[loc] - cur_freq;
            }
        }
        return true;
    }
};
