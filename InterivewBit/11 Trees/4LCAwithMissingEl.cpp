/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - LCA with missing elements.
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* findLCA(TreeNode* root, int a, int b, bool &n1, bool &n2) {
    if (root == NULL)
        return root;

    if (root->val == a) {
        n1 = true;
        return root;
    }

    if (root->val == b) {
        n2 = true;
        return root;
    }

    TreeNode* left = findLCA(root->left, a, b, n1, n2);
    TreeNode* right = findLCA(root->right, a, b, n1, n2);

    if (left and right)
        return root;

    if (left)
        return left;
    if (right)
        return right;
}

bool find(TreeNode* root, int key) {
    if (root == NULL)
        return false;

    if (root->val == key)
        return true;

    bool left = find(root->left, key);
    bool right = find(root->right, key);

    return left or right;
}

int Solution::lca(TreeNode* A, int B, int C) {
    bool n1 = false, n2 = false;
    TreeNode* l = findLCA(A, B, C, n1, n2);

    if (n1 and n2)
        return l->val;
    if (n1 and find(l, C))
        return l->val;
    if (n2 and find(l, B))
        return l->val;

    return -1;
}
