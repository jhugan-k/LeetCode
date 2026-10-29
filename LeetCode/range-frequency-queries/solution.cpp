class RangeFreqQuery {
public:
    // store locations of all indexes: map: {value} - {indexes}
    // when queried: find first index >= left and last index <= right 
    // count difference between these idx to get freq.


    unordered_map<int,vector<int>> mpp;

    RangeFreqQuery(vector<int>& arr) {
        for(int i = 0; i < arr.size(); i++){
            mpp[arr[i]].push_back(i); // already in sorted order
        }
    }
    
    int query(int left, int right, int value) {
        const vector<int> &v = mpp[value];
        //bs for >= left 
        int low = 0;
        int high = v.size()-1;
        int ans1 = -1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            // v[mid] = the index in question
            if(v[mid] >= left){
                // possible ans
                ans1 = mid;
                // try reducing 
                high = mid - 1;
            
            }
            else{
                // mid < left 
                // move mid up 
                low = mid + 1;
            }
        }
        int ans2 = -1;
        low = 0;
        high = v.size()-1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(v[mid] <= right){
                // valid ans 
                ans2 = mid;
                low = mid + 1;
            }
            else{
                // mid > right. reduce mid
                high = mid - 1;
            }
        }
        if(ans1 == -1 || ans2 == -1){
            // no index >= left. 0 freq 
            // no index <= right. 0 freq. 
            return 0;
        }
        // count 
        return(ans2 - ans1 + 1);
        

    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */