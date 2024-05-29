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
    int helper(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode * &ans){
        if(root == NULL){
            return 0;
        }
        int left = helper(root->left,p,q,ans);
        int right = helper(root->right, p, q, ans);
        if((left == 1 && right == 1) || ((root == p || root == q) && (left + right == 1))){
            ans = root;
        }
        if(root == p || root == q){
            return 1+ left + right;
        }
        return left + right;

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode * ans;
        helper(root,p,q,ans);
        return ans;
    }
};