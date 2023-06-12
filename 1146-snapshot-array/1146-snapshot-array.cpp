class SnapshotArray {
public:
    vector<unordered_map<int,int>>mp; int id=0;
    SnapshotArray(int length) {
        mp.resize(length);
    }
    
    void set(int index, int val) {
        mp[index][id]=val;
    }
    
    int snap() {
        
        return id++;
    }
    
    int get(int index, int snap_id) {
        while (snap_id >= 0 && mp[index].find(snap_id) == mp[index].end()) {
            snap_id--;
        }
        return mp[index][snap_id];
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */