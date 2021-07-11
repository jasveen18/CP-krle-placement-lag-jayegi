/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Path to given node
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool pathToTree(TreeNode* root, int key, vector<int> &res) {
    if (root == NULL)
        return false;

    if (root->val == key) {
        res.push_back(root->val);
        return true;
    }

    res.push_back(root->val);
    bool left = pathToTree(root->left, key, res);
    bool right = pathToTree(root->right, key, res);

    if (left or right)
        return true;

    // Backtrack
    res.pop_back();
    return false;
}

vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> res;
    pathToTree(A, B, res);

    return res;
}
