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
    // bfs 
    // mark parents of each node
    // at each node, check grandparent 
    // if -1, continue 
    // if gp ,check if even 
    
    int sumEvenGrandparent(TreeNode* root) {
        int sum = 0;
        queue<TreeNode*> q;
        q.push(root);
        unordered_map<TreeNode*, TreeNode*> parent;
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            // push children 
            if(node->left){
                q.push(node->left);
                parent[node->left] = node;
            } 
            if(node->right){
                q.push(node->right);
                parent[node->right] = node;
            }
            // check GP 
            if(parent.find(node) != parent.end()){
                // node has a parent. check GP 
                auto currParent = parent[node];
                if(parent.find(currParent) != parent.end()){
                    //currParent has a parent. GP exists 
                    auto GP = parent[currParent];
                    int temp = GP->val;
                    if((temp % 2) == 0) sum += node->val;
                }
            }
        }
        return sum;
    }
};