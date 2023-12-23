class Solution {
public:
    bool isPathCrossing(string path) {
        // pair<int,int> current={0,0};
        // unordered_map<string,bool> um;
        // um["0,0"] = true;

        // // pair<int,int> newPoint;
        
        // string tmp;
        
        // for(char ele:path) 
        // {
        //     if(ele=='N') {
        //         current.second++;
        //     }

        //     else if(ele == 'E') {
        //         current.first--;
        //     }

        //     else if(ele=='W') {
        //         current.first++;
        //     }

        //     else {
        //         current.second--;
        //     }
        //     tmp = to_string(current.first) + "," + to_string(current.second);
        //     if(um[tmp] == false) {
        //         um[tmp]=true;
        //     }
        //     else {
        //         return true;
        //     }
        // }
        // return false;

        int x=0,y=0;
        
        map<pair<int,int>,bool>vis;
        
        for(int i=0;i<path.size();i++)
        {
           if( vis[{x,y}]==1) return 1;
            
            vis[{x,y}]=1;
            
            char ch=path[i];
            
            switch (ch){
                case 'N' : y++;
                break;
                case 'S' :y--;
                break;
                case 'E' : x++;
                break;
                case 'W' : x--;
                break;
            }  
        } 
        
        if( vis[{x,y}]==1) return 1;
        return 0;
    }
};
