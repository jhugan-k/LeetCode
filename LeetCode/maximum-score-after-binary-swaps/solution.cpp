class Solution {
public:
    long long maximumScore(vector<int>& nums, string s) {
        // track best candidates in heap
        // if find 1: compare current with best candidate. 
        // if current equal bigger, continue. 
        // else, current smaller, take heap.top and add to sum (1 will be sent there) set current to 0 and push into heap. 
        priority_queue<int> pq;
        long long maxSum = 0;
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '1'){
                if(pq.empty()){
                    // no candidate. add current
                    maxSum += nums[i];
                    continue;
                }
                else if(pq.top() > nums[i]){
                    //candidate exists and is better
                    maxSum += pq.top();
                    pq.pop();
                    pq.push(nums[i]); //current is now a candidate 
                }
                else{
                    // candidate exists but is not better
                    maxSum += nums[i];
                    continue;
                }
            }
            else{
                // s[i] = 0. add as candidate
                pq.push(nums[i]);
            }
            
        }
        return maxSum;
    }
};