class Solution {
public:
    // recursion / DP 
    // choice 1 : i + arr[i]
    // choice 2 : i - arr[i]
    // base case: outside or arr[i] = 0. 

    bool solve(int i, vector<int> &arr, vector<int> &visited){
        if(i >= arr.size()) return false;
        if(i < 0) return false;
        if(arr[i] == 0) return true;
        bool c1 = false;
        bool c2 = false;
        if(i + arr[i] < arr.size() && !visited[i + arr[i]]){
            visited[i + arr[i]] = 1;
            c1 = solve(i + arr[i], arr, visited);
        }
        if(i - arr[i] >= 0 && !visited[i - arr[i]]){
            visited[i - arr[i]] = 1;
            c2 = solve(i - arr[i], arr, visited);
        }
        return (c1 || c2);
              
    }
    bool canReach(vector<int>& arr, int start) {
        vector<int> visited(arr.size(), 0);
        visited[start] = 1;
        return solve(start, arr, visited);
    }
};