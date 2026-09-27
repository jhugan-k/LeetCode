class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // at most k stops: at most k+1 flights 
        // k+1 iterations for bellman ford. 

        vector<int> dist(n, 1e9);
        dist[src] = 0;

        for(int i = 0; i <= k; i++){
            vector<int> temp = dist;
            for(auto flight : flights){
                int u = flight[0];
                int v = flight[1];
                int price = flight[2];
                //check if u is reachable
                if(dist[u] != 1e9){
                    //try to go to v
                    temp[v] = min(temp[v], dist[u] + price);
                }
            }
            //move to next lvl
            dist = temp;
        }
        if(dist[dst] == 1e9) return -1;
        else return dist[dst];
    }
};