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
    TreeNode* firstVio = NULL;
    TreeNode* secondVio = NULL;
    TreeNode* prev = NULL;
    bool firstViolationFound = 0;
    bool secondViolationFound = 0;

    void inorder(TreeNode* root){
        if(firstViolationFound && secondViolationFound) return; //work is done
        if(!root) return;
        if(root->left) inorder(root->left);
        
        if(prev){
            //compare vals
            if(prev->val > root->val){
                //violation. check if first violation was found already
                if(!firstViolationFound){
                    //not found yet, this is first violation
                    firstViolationFound = 1;
                    firstVio = prev;
                    secondVio = root; //default case: if no second violation exists
                }
                else{
                    //this is second violation
                    secondViolationFound = 1;
                    secondVio = root; 
                    return;
                }
            }
        }
        prev = root;
        
        if(root->right) inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(firstVio->val, secondVio->val);
        return;
    }
};