/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;

        map<int,vector<pair<int,int>>> mpp;
        queue<pair<TreeNode*, int>> q;
        
        int rowNumber = 0;
        q.push({root,0});
        while(!q.empty()){
            int rowCount = q.size();
            for(int i = 0; i < rowCount; i++){
                TreeNode* temp = q.front().first;
                int pos = q.front().second;

                if(temp != NULL){
                    //map: int, vector<pair<int,int>
                    //map: position, vector<pair<rowNumber, value>
                    //insert now, sort later by row first then value 
                    mpp[pos].push_back({rowNumber, temp->val});
                }

                if(temp->left) q.push({temp->left, pos - 1});
                if(temp->right) q.push({temp->right, pos + 1});

                q.pop();
            }
            rowNumber++;
            
        }
        //iterate over map and retrieve by column
        for(auto it : mpp){
            auto v = it.second;
            sort(v.begin(), v.end());
            vector<int> tempAns;
            for(auto it : v) tempAns.push_back(it.second);
            ans.push_back(tempAns);
        }
        return ans;
        
    }
};