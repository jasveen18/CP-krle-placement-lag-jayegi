/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Sum root to leaf
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void findSum(TreeNode* root, int currNum, int &res, int multiplier) {
    if (root == NULL)
        return;

    currNum = (currNum * 10) % 1003;
    currNum += (root->val) % 1003;

    if (root->left == NULL and root->right == NULL) {
        res += currNum % 1003;
        return;
    }

    findSum(root->left, currNum, res, multiplier);
    findSum(root->right, currNum, res, multiplier);

    return;
}


int Solution::sumNumbers(TreeNode* A) {
    if (A == NULL)
        return 0;

    int res = 0;
    int currNum = 0;
    int multiplier = 1;

    findSum(A, currNum, res, multiplier);
    return res % 1003;
}
