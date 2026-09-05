class disjointSet{
    public:
    vector<int>parent, rank;

    disjointSet(int n){
        parent.resize(n + 1);
        rank.resize(n + 1);
        for(int i = 0; i < n + 1; i++){
            parent[i] = i;
            rank[i] = 0;
        }
    }
    
    int findParent(int node){
        if(parent[node] == node) return node;
        parent[node] = findParent(parent[node]);
        return parent[node];
    }

    void unionByRank(int u, int v){
        int pu = findParent(u);
        int pv = findParent(v);

        if(pu == pv) return;
        if(rank[pu] > rank[pv]) parent[pv] = pu;
        else if(rank[pu] < rank[pv]) parent[pu] = pv;
        else{
            parent[pu] = pv;
            rank[pv]++;
        }
    }
};
class Solution {
public:

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        disjointSet ds(n);
        map<string,int> mpp;
        int index = -1;
        for(auto account : accounts){
            index++;

            for(int i = 1; i < account.size(); i++){
                string email = account[i];

                if(mpp.find(email) == mpp.end()){
                    mpp[email] = index;
                }

                else{
                    //already exists
                    //findout existing index 
                    int og = mpp[email];
                    //join index to og.
                    ds.unionByRank(index, og);

                }
            }
            
        }
        unordered_map<int, vector<string>> merged;
        for(auto& [mail, idx] : mpp){
            int par = ds.findParent(idx);
            merged[par].push_back(mail);

        }
        vector<vector<string>> ans;
        for(auto& [par,emails] : merged){
            sort(emails.begin(), emails.end());
            vector<string>temp;
            temp.push_back(accounts[par][0]);
            temp.insert(temp.end(), emails.begin(), emails.end());
            ans.push_back(temp);
        }
        return ans;
        
    }
};