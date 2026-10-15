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
    // moves: leftCoins + rightCoins: extra coins from both are transferred among immediate neighbours 
    // leftCoins / rightCoins: coins needed to keep 1 at current node 
    // build from leaf 
    int moves = 0;

    int dfs(TreeNode* root){
        if(root == NULL) return 0;
        int leftCoins = dfs(root->left);
        int rightCoins = dfs(root->right);
        int currCoins = (root->val - 1) + leftCoins + rightCoins; //coin overflow or underflow 
        moves += abs(leftCoins) + abs(rightCoins);
        return currCoins;

    }
    int distributeCoins(TreeNode* root) {
        int temp = dfs(root);
        return moves;
    }
};