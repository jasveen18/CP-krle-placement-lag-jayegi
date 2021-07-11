/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Min Depth of Tree
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void depth(TreeNode* root, int &ans, int dep) {
    if (root == NULL) {
        return;
    }

    if (root->left == NULL and root->right == NULL) {
        ans = min(ans, dep);
        return;
    }

    depth(root->left, ans, dep + 1);
    depth(root->right, ans, dep + 1);
    return;
}

int Solution::minDepth(TreeNode* A) {
    if (A == NULL)
        return 0;

    int ans = INT_MAX;
    depth(A, ans, 1);

    return ans;
}
