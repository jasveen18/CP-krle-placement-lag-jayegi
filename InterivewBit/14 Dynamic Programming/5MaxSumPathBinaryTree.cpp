/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Find max sum path from any node to another node.
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int getMaxGain(TreeNode* root, int &maxPath) {
    if (root == NULL)
        return INT_MIN / 5;

    int gainLeft = getMaxGain(root->left, maxPath);
    int gainRight = getMaxGain(root->right, maxPath);

    int completePath = root->val + gainLeft + gainRight;
    int onlyRoot = root->val;
    maxPath = max(maxPath, max(completePath, onlyRoot));

    return max(root->val + max(gainLeft, gainRight), onlyRoot);
}

int Solution::maxPathSum(TreeNode* A) {
    int maxPath = INT_MIN / 5;
    getMaxGain(A, maxPath);

    return maxPath;
}



// Leet code solution which got accepted and a little clean ->
int getMaxGain(TreeNode* root, int &maxPath) {
    if (root == NULL)
        return 0;

    // Take the max gain from both sides
    int gainLeft = max(getMaxGain(root->left, maxPath), 0);
    int gainRight = max(getMaxGain(root->right, maxPath), 0);

    // Check if we can include the root to join both sides to get answer
    int completePath = root->val + gainLeft + gainRight;
    maxPath = max(maxPath, completePath);

    // Return the answer with only one path, kyunki path m koi hi side hoga
    return root->val + max(gainLeft, gainRight);
}

int maxPathSum(TreeNode* root) {
    int maxPath = root->val;
    getMaxGain(root, maxPath);

    return maxPath;
}