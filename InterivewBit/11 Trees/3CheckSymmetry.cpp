/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Check if tree is symmetric
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int checkSymmetric(TreeNode* A, TreeNode* B) {
    if (A == NULL and B == NULL)
        return 1;

    if (A == NULL or B == NULL)
        return 0;

    if (A->val != B->val)
        return 0;

    int left = checkSymmetric(A->left, B->right);
    int right = checkSymmetric(A->right, B->left);

    return left and right;
}

int Solution::isSymmetric(TreeNode* A) {
    return checkSymmetric(A, A);
}
