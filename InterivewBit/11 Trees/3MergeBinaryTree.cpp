/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Merge Binary Tree
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::solve(TreeNode* A, TreeNode* B) {
    // Base Case -
    if (A == NULL)
        return B;
    if (B == NULL)
        return A;

    // Recursive Case -
    if (A and B) {
        A->val = A->val + B->val;
    }

    A->left = solve(A->left, B->left);
    A->right = solve(A->right, B->right);

    return A;
}
