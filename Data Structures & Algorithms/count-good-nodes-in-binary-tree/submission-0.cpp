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
    int helper(TreeNode* root, int ans, int currmax){
        if(root == NULL)    return 0;
        int currans = 0;
        if(root->val >= currmax){
            currans = 1;
            currmax = root->val;
        }

        int lans = helper(root->left,currans,currmax);
        int rans = helper(root->right,currans,currmax);
        return lans + rans + currans;
    }
    int goodNodes(TreeNode* root) {
        return helper(root,0,root->val);
    }
};
