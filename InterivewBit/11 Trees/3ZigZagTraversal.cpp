/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - ZigZag Traversal
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    if (A == NULL)
        return {};

    vector<vector<int>> res;
    queue<TreeNode*> q;
    q.push(A);
    bool zig = false;

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
        if (zig) {
            reverse(temp.begin(), temp.end());
            zig = false;
        } else {
            zig = true;
        }
        res.push_back(temp);
    }

    return res;
}
