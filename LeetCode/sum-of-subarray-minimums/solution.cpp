class Solution {
public:
    /*
    > find contribution of each arr[i] to the sum of subarray minimum
    > contribution of element = arr[i] * number of subarrays it is minimum in
    > to find number of subarrays an arr[i] contributes to, calculate its next lesser element and previous lesser element 
    > total number of subarrays = (i - ple) * (nle - i), contribution = *arr[i]
    > add all contributions
    >> to find PLE and NLE: use monotonic stack holding index, and store PLE and NLE in seperate array
    >> iterate over array and for PLE skip >, NLE skip >= = only in one side because interval

    */

    int sumSubarrayMins(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        vector<int> ple(arr.size());
        vector<int> nle(arr.size());
        stack<int>st;
        //find ple
        for(int i = 0; i < arr.size(); i++){
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop(); //skip > elements
            ple[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        //find nle
        while(!st.empty()) st.pop();
        for(int i = arr.size() - 1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            nle[i] = st.empty() ? arr.size() : st.top();
            st.push(i);
        }

        //find result
        long long ans = 0;
        for(int i = 0; i < arr.size(); i++){
            long long left = i - ple[i];
            long long right = nle[i] - i;
            long long contrib = (arr[i] % MOD) * (left % MOD) % MOD * (right % MOD) % MOD;
            ans = (ans + contrib) % MOD;
        }
        return (int)ans;
    }
};