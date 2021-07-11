/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Path Sum
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void findPath(TreeNode* root, int k, int sumhere, bool &ans) {
    if (root == NULL)
        return;

    sumhere += root->val;
    if (sumhere == k and root->left == NULL and root->right == NULL) {
        ans = true;
        return;
    }

    findPath(root->left, k, sumhere, ans);
    findPath(root->right, k, sumhere, ans);
    return;
}

int Solution::hasPathSum(TreeNode* A, int B) {
    int sumhere = 0;
    bool ans = false;

    findPath(A, B, sumhere, ans);
    return ans;
}
