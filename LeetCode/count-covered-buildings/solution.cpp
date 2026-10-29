class Solution {
public:
    // group buildings 
    // for each row, need min_y and max_y 
    // for each col, need min_x and max_x 

    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<int> min_x (n+1, n+1);
        vector<int> max_x (n+1, 0);
        vector<int> min_y (n+1, n+1);
        vector<int> max_y (n+1, 0);

        for(auto building : buildings){
            int x = building[0];
            int y = building[1];
            min_x[y] = min(min_x[y], x);
            max_x[y] = max(max_x[y], x);
            min_y[x] = min(min_y[x], y); 
            max_y[x] = max(max_y[x], y);
        }
        int ans = 0;

        for(auto building : buildings){
            int x = building[0];
            int y = building[1];
            if(x > min_x[y] && x < max_x[y] && y > min_y[x] && y < max_y[x]) ans++;
        }
        return ans;

        return ans;

    }
};