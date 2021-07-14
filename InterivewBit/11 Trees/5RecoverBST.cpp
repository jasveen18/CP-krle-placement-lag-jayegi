/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Recover BST
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void goFindSwappedElements(TreeNode* root, TreeNode* &first, TreeNode* &second, TreeNode* &prev) {
    if (root == NULL)
        return;

    goFindSwappedElements(root->left, first, second, prev);

    // Logic
    if (first == NULL and prev->val >= root->val) // First Not Found
        first = prev;
    if (first != NULL and prev->val >= root->val) // First found, now update second
        second = root; // This will be root, run an example and see
    prev = root;

    goFindSwappedElements(root->right, first, second, prev);
}


vector<int> Solution::recoverTree(TreeNode* A) {
    TreeNode* firstEl = NULL;
    TreeNode* secondEl = NULL;
    TreeNode* prev = new TreeNode(INT_MIN); // to avoid run time errors

    goFindSwappedElements(A, firstEl, secondEl, prev);
    return {secondEl->val, firstEl->val};
}
