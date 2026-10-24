class Solution {
public:
    int distinctPoints(string s, int k) {
        // calculate net difference for each substring removal: prefix[end+1] - prefix[start-1]
        // this is net difference from final point after removal 
        // store in set 
        // if already appeared, count, otherwise don't
        vector<int> prefixx(s.size(), 0);
        vector<int> prefixy(s.size(), 0);
        int net_x = 0;
        int net_y = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'U'){
                net_y++;
            }
            if(s[i] == 'D'){
                net_y--;
            }
            if(s[i] == 'L'){
                net_x--;
            }
            if(s[i] == 'R'){
                net_x++;
            }
            prefixx[i] = net_x;
            prefixy[i] = net_y;
        }
        set<pair<int,int>> st;
        int ans = 0;
        
        for(int end = s.size()-1; end >= k-1; end--){
            int start = end-k+1;
            //delete substr from start to end
            int netChangeX = 0;
            int netChangeY = 0;
            
            if(end < s.size()) netChangeX = prefixx[end]; //otehrwhise whole 
            if(start-1 >= 0) netChangeX -= prefixx[start-1]; //otherwise no sub

            if(end < s.size()) netChangeY = prefixy[end]; //otehrwhise whole 
            if(start-1 >= 0) netChangeY -= prefixy[start-1]; //otherwise no sub

            if(st.find({netChangeX, netChangeY}) == st.end()){
                st.insert({netChangeX, netChangeY});
                ans++; //found new change
            }
        }
        return ans;
        
    }
};