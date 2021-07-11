/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Find Kth Smallest
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void inorder(TreeNode* A, int &B, int &ans) {
    if (A == NULL)
        return;

    inorder(A->left, B, ans);
    B--;
    if (B == 0) {
        ans = A->val;
        return;
    }

    inorder(A->right, B, ans);
}

int Solution::kthsmallest(TreeNode* A, int B) {
    int ans = A->val;
    inorder(A, B, ans);

    return ans;
}
