class Solution {
public:
    void dfs(vector<vector<int>> &adj, vector<int> &step, vector<int> &low, vector<int> &visited, int node, int parent, int &dfscount, vector<vector<int>> &bridges){
        
        visited[node] = 1;
        dfscount++;
        step[node] = dfscount;
        low[node] = step[node];

        for(auto nbr : adj[node]){
            if(nbr == parent) continue;
            if(!visited[nbr]){
                dfs(adj,step,low,visited,nbr,node,dfscount,bridges);
                low[node] = min(low[node], low[nbr]);
                
                //check for bridge 
                if(step[node] < low[nbr]) bridges.push_back(vector<int>{node,nbr});
            }
            else{
                //back edge. update low 
                low[node] = min(low[node], step[nbr]);
            }
        }
        return;
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        //convert connections to adjList
        vector<vector<int>>adj(n);

        vector<int> visited(n, 0);
       
        
        int dfscount = 0;

        for(auto connection : connections){
            int u = connection[0];
            int v = connection[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int>step(n);
        vector<int>low(n);
        vector<vector<int>> bridges;
        

        dfs(adj,step,low,visited,0,-1,dfscount,bridges);
        return bridges;
    }
};