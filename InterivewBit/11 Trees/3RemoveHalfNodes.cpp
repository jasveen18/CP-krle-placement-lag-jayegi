/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Remove nodes having only one children
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


TreeNode* Solution::solve(TreeNode* A) {
    // Postorder krke dekhte hai.
    if (A == NULL)
        return A;

    if (A->left == NULL and A->right == NULL)
        return A;

    A->left = solve(A->left);
    A->right = solve(A->right);

    if (A->left == NULL and A->right) {
        return A->right;
    }

    if (A->right == NULL and A->left) {
        return A->left;
    }

    return A;
}
