/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Identical binary trees hai ya ni?
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::isSameTree(TreeNode* A, TreeNode* B) {
    if (A == NULL and B == NULL)
        return 1;

    if (A == NULL or B == NULL)
        return 0;

    if (A->val != B->val)
        return 0;

    int left = isSameTree(A->left, B->left);
    int right = isSameTree(A->right, B->right);

    if (left == 0 or right == 0)
        return 0;

    return 1;
}
