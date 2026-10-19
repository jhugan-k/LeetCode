class ExamTracker {
public:
    ExamTracker() {
        
    } 
    vector<int> times;
    vector<long long> prefix;
    
    void record(int time, int score) { 
        times.push_back(time);
        if(prefix.size() == 0) prefix.push_back(score);
        else prefix.push_back(prefix.back() + score);
    }
    // times come in sorted order 
    // store all times, and keep running prefix array 
    // totalScore: binary search for >= StartTime, <= endTime. take indexes, calculate prefix sum
    
    long long totalScore(int startTime, int endTime) { 
        // bs for >= startTime 
        int low = 0;
        int high = times.size();
        int ans1 = -1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(mid < times.size() && times[mid] >= startTime){
                //could be ans. look for smaller ans 
                ans1 = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1; //time[mid] is smaller than start time. increase it
            }
        }
        int ans2 = -1; 
        low = 0;
        high = times.size();
        while(low <= high){
            int mid = low + (high - low) / 2;
            // look for times[mid] <= endTime 
            if(mid < times.size() && times[mid] <= endTime){
                ans2 = mid;
                //check for larger mid 
                low = mid + 1;
            }
            else{
                // went past endtime. lower mid 
                high = mid - 1;
            }
        }
        if(ans1 == -1 || ans2 == -1){
            // no one >= startTime, or <= endTime. return 0.
            return 0;
        }
        //take prefix to get sum 
        // ans1: start, ans2: end 
        long long sum2 = prefix[ans2];
        long long sum1 = 0;
        if(ans1 > 0) sum1 = prefix[ans1 - 1];
        return (sum2 - sum1);
    }
};

/**
 * Your ExamTracker object will be instantiated and called as such:
 * ExamTracker* obj = new ExamTracker();
 * obj->record(time,score);
 * long long param_2 = obj->totalScore(startTime,endTime);
 */