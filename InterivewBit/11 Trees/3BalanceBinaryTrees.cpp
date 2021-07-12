/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Balance Binary Trees
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int solveBalance(TreeNode* A, bool &ans) {
    if (A == NULL)
        return 0;

    int left = solveBalance(A->left, ans);
    int right = solveBalance(A->right, ans);

    ans = ans and (abs(left - right) <= 1);

    return max(left, right) + 1;
}

int Solution::isBalanced(TreeNode* A) {
    bool ans = 1;
    solveBalance(A, ans);

    return ans;
}
