class Solution {
public:
    // multiple initial scans. 
    // L-R, R-L, U-D, D-U 

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        //L-R
        vector<vector<int>> seen(m, vector<int> (n, 0));
        // 0: unseen, no guard
        // 1: seen, no guard
        // 2: guard
        // 3: wall 
        for(auto guard : guards){
            int x = guard[0];
            int y = guard[1];
            seen[x][y] = 2;
        }
        for(auto wall : walls){
            int x = wall[0];
            int y = wall[1];
            seen[x][y] = 3;
        }
        // L to R
        for(int i = 0; i < m; i++){
            bool foundGuard = 0;
            for(int j = 0; j < n; j++){
                if(seen[i][j] == 0){
                    //unseen
                    //check if guard found
                    if(foundGuard) seen[i][j] = 1;
                }
                if(seen[i][j] == 1){
                    //seen
                    continue;
                }
                if(seen[i][j] == 2){
                    //guard
                    foundGuard = 1;
                }
                if(seen[i][j] == 3){
                    // wall
                    //reset guard sight, if any 
                    foundGuard = 0;
                }
            }
        }
        //R to L 
        for(int i = 0; i < m; i++){
            bool foundGuard = 0;
            for(int j = n-1; j >= 0; j--){
                if(seen[i][j] == 0){
                    //unseen
                    //check if guard found
                    if(foundGuard) seen[i][j] = 1;
                }
                if(seen[i][j] == 1){
                    //seen
                    continue;
                }
                if(seen[i][j] == 2){
                    //guard
                    foundGuard = 1;
                }
                if(seen[i][j] == 3){
                    // wall
                    //reset guard sight, if any 
                    foundGuard = 0;
                }
            }
        }
        //U to D 
        for(int j = 0; j < n; j++){
            bool foundGuard = 0;
            for(int i = 0; i < m; i++){
                if(seen[i][j] == 0){
                    //unseen
                    //check if guard found
                    if(foundGuard) seen[i][j] = 1;
                }
                if(seen[i][j] == 1){
                    //seen
                    continue;
                }
                if(seen[i][j] == 2){
                    //guard
                    foundGuard = 1;
                }
                if(seen[i][j] == 3){
                    // wall
                    //reset guard sight, if any 
                    foundGuard = 0;
                }
            }
        }
        // D to U
        for(int j = 0; j < n; j++){
            bool foundGuard = 0;
            for(int i = m-1; i >= 0; i--){
                if(seen[i][j] == 0){
                    //unseen
                    //check if guard found
                    if(foundGuard) seen[i][j] = 1;
                }
                if(seen[i][j] == 1){
                    //seen
                    continue;
                }
                if(seen[i][j] == 2){
                    //guard
                    foundGuard = 1;
                }
                if(seen[i][j] == 3){
                    // wall
                    //reset guard sight, if any 
                    foundGuard = 0;
                }
            }
        }
        //check seen
        int count = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(seen[i][j] == 0) count++;
            }
        }
        return count;
    }
};