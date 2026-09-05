/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    //find path to both p and q, store in array
    //find first node where path is same
    void pathfinder(int target, TreeNode* root, vector<TreeNode*> &path, vector<TreeNode*> &ans){
        if(root == NULL) return;
        path.push_back(root);
        if(root->val == target){
            ans = path;
            return;
        }
        pathfinder(target, root->left, path, ans);
        pathfinder(target, root->right, path, ans);

        path.pop_back(); 

    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> p_path;
        vector<TreeNode*> q_path;
        vector<TreeNode*> temp;
        
        pathfinder(p->val, root, temp, p_path);
        temp.clear();
        pathfinder(q->val, root, temp, q_path);
        //compare both paths
        int minSize = min(p_path.size(), q_path.size());

        TreeNode* lca = root;

        for(int i = 0; i < minSize; i++){
            if(p_path[i]->val == q_path[i]->val){
                //found LCA
                lca = p_path[i];
            }
        }
        return lca;
    }
};