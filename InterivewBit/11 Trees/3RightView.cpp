/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Return the right view of the tree.
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::solve(TreeNode* A) {
    map<int, int> mp;
    queue<pair<TreeNode*, int>> q;

    if (A == NULL)
        return {};

    vector<int> res;

    q.push({A, 0});

    while (!q.empty()) {
        TreeNode* curr = q.front().first;
        int rank = q.front().second;
        q.pop();

        mp[rank] = curr->val;
        if (curr->left)
            q.push({curr->left, rank + 1});
        if (curr->right)
            q.push({curr->right, rank + 1});
    }

    for (auto el : mp) {
        res.push_back(el.second);
    }

    return res;
}
