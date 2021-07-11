/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Build Cartesian Tree
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* buildTheTree(vector<int> &A, int start, int end) {
    if (start > end)
        return NULL;

    // Find the max element index
    int idx = start;
    for (int i = start; i <= end; i++) {
        if (A[idx] < A[i])
            idx = i;
    }

    TreeNode* root = new TreeNode(A[idx]);

    root->left = buildTheTree(A, start, idx - 1);
    root->right = buildTheTree(A, idx + 1, end);

    return root;
}


TreeNode* Solution::buildTree(vector<int> &A) {
    // reverse(A.begin(), A.end());
    int n = A.size();

    if (n == 1)
        return new TreeNode(A[0]);

    return buildTheTree(A, 0, n - 1);
}
