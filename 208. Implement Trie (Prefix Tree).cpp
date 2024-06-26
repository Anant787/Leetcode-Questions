class Trie {
public:
    set<string> st;    //set of string
    Trie(){}
    void insert(string word) {
        st.insert(word);        //insert into the set
    }

    bool search(string word) {
        return st.find(word) != st.end();     //check the condition
    }
    
    bool startsWith(string prefix) {

        auto it = st.lower_bound(prefix);
        if(it == st.end()) 
            return false;
        for(int i = 0;i<prefix.size();i++){
            if(prefix[i] != (*it)[i]){
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
