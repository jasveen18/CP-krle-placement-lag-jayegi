/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Sorted array to BST
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* makeTree(const vector<int> &A, int start, int end) {
    if (start > end)
        return NULL;

    int mid = start + (end - start) / 2;
    TreeNode* root = new TreeNode(A[mid]);

    root->left = makeTree(A, start, mid - 1);
    root->right = makeTree(A, mid + 1, end);

    return root;
}

TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    int n = A.size();

    if (n == 1)
        return new TreeNode(A[0]);

    TreeNode* root = makeTree(A, 0, n - 1);
    return root;
}
