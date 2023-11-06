class SeatManager {
    private:
    int low;           // Global Declare
    vector<bool> seats;
    priority_queue<int, vector<int>, greater<int>> minHeap;
public:
    SeatManager(int n) {

    }
    
    int reserve() {
        if(!minHeap.empty())
        {
            int seatNumber = minHeap.top();
            minHeap.pop();
            seats[seatNumber] = true;
            return seatNumber+1;
        }
        seats.push_back(true);
        return seats.size();
    }
    
    void unreserve(int seatNumber) 
    {
        minHeap.push(seatNumber-1);
        seats[seatNumber-1] = false;
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
