class Solution {
public:
    void findDist(int n, vector<vector<int>> &adj, int src, vector<int> &dist){
        queue<int> q;
        vector<int> visited(n,0);
        visited[src] = 1;
        q.push(src);

        int currLevel = 0;
        while(!q.empty()){
            int levelSize = q.size();
            for(int i = 0; i < levelSize; i++){
                int node = q.front();
                dist[node] = currLevel;
                q.pop();
                
                for(auto nbr : adj[node]){
                    if(!visited[nbr]){
                        visited[nbr] = 1;
                        q.push(nbr);
                    }
                }
            }
            currLevel++;
        }
        return;
        
    }
    
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        vector<vector<int>> adj(n);
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> dx(n, 0);
        vector<int> dy(n, 0);
        vector<int> dz(n, 0);
        
        findDist(n, adj, x, dx);
        findDist(n, adj, y, dy);
        findDist(n, adj, z, dz);

        int count = 0;
        
        for(int i = 0; i < dx.size(); i++){
            vector<int> temp = {dx[i], dy[i], dz[i]}; //set of distances
            sort(temp.begin(), temp.end());
            long long v1 = (1LL * temp[0] * temp[0]) + (1LL * temp[1] * temp[1]);
            long long v2 = (1LL * temp[2] * temp[2]);
            if(v1 == v2) count++;
        }

        return count;
    }
};