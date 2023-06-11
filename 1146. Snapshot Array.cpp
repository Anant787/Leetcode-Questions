class SnapshotArray {
public:
    // One of the approach is Mapping, ANother is Binary search
    SnapshotArray(int length) {
        
    }
    
    void set(int index, int val) {
        array[index][snap_id] = val;
        
    }
    
    int snap() {
        return snap_id++;
        
    }
    
    int get(int index, int snap_id) {
        array[index][0];
        return prev(array[index].upper_bound(snap_id))->second;
        
    }
    private:
    int snap_id = 0;
    unordered_map<int,map<int,int>>array;
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
