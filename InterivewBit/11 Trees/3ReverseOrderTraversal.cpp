/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Reverse order traversal
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
    if (A == NULL)
        return {};

    vector<vector<int>> res;
    queue<TreeNode*> q;
    q.push(A);

    while (!q.empty()) {
        int size = q.size();
        vector<int> temp;

        for (int i = 0; i < size; i++) {
            TreeNode* curr = q.front();
            temp.push_back(curr->val);
            q.pop();

            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }

        res.push_back(temp);
    }

    reverse(res.begin(), res.end());
    vector<int> ans;

    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++)
            ans.push_back(res[i][j]);
    }

    return ans;
}
