class Solution {
public:
    class disjointSet{
        public:
        vector<int> parent;
        vector<int> size;

        disjointSet(int n){
            parent.resize(n+1,0);
            size.resize(n+1,1);
            for(int i = 0; i < n; i++){
                parent[i] = i;
            }
        }
        int findParent(int node){
            if(parent[node] == node) return node;
            else parent[node] = findParent(parent[node]); 
            return parent[node];
        }
        void unionBySize(int u, int v){
            int ulp_u = findParent(u);
            int ulp_v = findParent(v);
            if(ulp_u == ulp_v) return; //same component 
            
            if(size[ulp_u] > size[ulp_v]){
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
            else{
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
        }
    };

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        // map each email to an account
        // if account already in use, join current account using dsu 
        // after all email mapped, create final list of ultimate parents and emails
        // list created: then go into each ulp, sort its emails, and push back in order to ans 
        int index = -1; //acc index
        disjointSet ds(accounts.size());

        unordered_map<string, int> mpp; //mails to acc
        for(auto account : accounts){
            index++;
            for(int i = 1; i < account.size(); i++){
                string mail = account[i];
                if(mpp.find(mail) == mpp.end()) mpp[mail] = index; //first occourence
                else{
                    //already posessed
                    int og = mpp[mail];
                    ds.unionBySize(index, og); //merge accounts
                }
            }
        }
        //all merged. create final list
        unordered_map<int, vector<string>> mpp2; 

        for(auto &[mail, acc] : mpp){
            int ulp = ds.findParent(acc);
            mpp2[ulp].push_back(mail);
        }

        vector<vector<string>> ans;
        for(auto &[parent, emails] : mpp2){
            vector<string> temp;
            temp.push_back(accounts[parent][0]); //acc name
            sort(emails.begin(), emails.end());
            for(auto &email : emails) temp.push_back(email); //push emails 
            ans.push_back(temp);
        }
        return ans;
    }
};