class BrowserHistory {
public:
    vector<string> ans;      //vector of string
    int curr;
    BrowserHistory(string homepage) {
        ans.push_back(homepage);
        curr = 1;
    }
    
    void visit(string url) {
        while(ans.size()>curr){
            ans.pop_back();
        }
        curr++;
        ans.push_back(url);
    }
    
    string back(int steps) {
        if((curr-steps<=0)){curr = 1;return ans[curr-1];}
        curr -= steps;
        return ans[curr-1];
    }
    
    string forward(int steps) {
        if((curr+steps)>ans.size()){curr = ans.size();return ans[curr-1];}
        curr += steps;
        return ans[curr-1];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
