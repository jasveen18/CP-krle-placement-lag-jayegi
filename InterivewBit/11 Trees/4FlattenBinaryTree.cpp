/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Flatten binary tree
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void flattenMe(TreeNode* root, TreeNode* &trav) {
    if (root == NULL) {
        return;
    }

    TreeNode* left = root->left;
    TreeNode* right = root->right;

    trav->right = root;
    trav->left = NULL;

    trav = trav->right;

    flattenMe(left, trav);
    flattenMe(right, trav);
}

TreeNode* Solution::flatten(TreeNode* A) {
    if (A == NULL)
        return NULL;

    // Preorder flatten krre hai
    TreeNode* root = new TreeNode(-1);
    TreeNode* trav = root;

    flattenMe(A, trav);

    trav->left = NULL;
    trav->right = NULL;

    return root->right;
}
