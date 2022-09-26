class Solution {
    int find(char x,unordered_map<char,char> & parent)
    {
        if(parent[x]!=x)
        {
            parent[x]=find(parent[x],parent);
        }
        return parent[x];
    }
    
public:
    bool equationsPossible(vector<string>& eq) {
        unordered_map<char,char>parent;
        
        for(auto x : eq)
        {
            parent[x[0]] = x[0];
            parent[x[3]] = x[3];
        }
        
        for(auto it : eq)
        {
            char x = find(it[0],parent);
            char y = find(it[3],parent);
            
            if(it[1]== '=')
            {
                parent[y]=x;
            }
        }
        
        for(auto it : eq)
        {
            char x = find(it[0],parent);
            char y = find(it[3],parent);
            
            if(it[1]== '!'   && x==y)
            {
                return false;
            }
        }
        
        return true;
        
    }
};