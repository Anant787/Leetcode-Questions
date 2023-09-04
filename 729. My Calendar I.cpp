class MyCalendar {
public:
    multiset<pair<int,int>> p ;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        int booking =0 ;
        // make the pairs 
        p.insert(make_pair(start,1));
        p.insert(make_pair(end,-1));

        for(auto i : p)
        {
            booking += i.second;   //value

            if(booking > 1)
            {
                p.erase(p.find(make_pair(start,1)));  // delete the recent pair
                p.erase(p.find(make_pair(end,-1)));
                return false;
            }
        }
        return true;

    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
