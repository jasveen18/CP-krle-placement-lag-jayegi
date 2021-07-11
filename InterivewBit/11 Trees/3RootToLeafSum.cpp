/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Root to leaf path sum
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void findPathSums(TreeNode* root, int k, int sumHere, vector<int> curr, vector<vector<int>> &res) {
    if (root == NULL)
        return;

    sumHere += root->val;
    curr.push_back(root->val);

    // if(sumHere > k)
    //     return;

    if (sumHere == k and root->left == NULL and root->right == NULL) {
        res.push_back(curr);
        return;
    }

    findPathSums(root->left, k, sumHere, curr, res);
    findPathSums(root->right, k, sumHere, curr, res);

    return;
}

vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
    vector<vector<int>> res;
    vector<int> curr;

    findPathSums(A, B, 0, curr, res);

    return res;
}
