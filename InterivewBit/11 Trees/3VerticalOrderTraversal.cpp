/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
    vector<vector<int>> res;
    map<int, vector<int>> level;

    if (A == NULL)
        return {};

    queue<pair<TreeNode*, int>> q;
    q.push({A, 0});

    while (!q.empty()) {
        TreeNode* curr = q.front().first;
        int rank = q.front().second;
        q.pop();

        level[rank].push_back(curr->val);

        if (curr->left)
            q.push({curr->left, rank - 1});
        if (curr->right)
            q.push({curr->right, rank + 1});
    }

    for (auto el : level)
        res.push_back(el.second);

    return res;
}
