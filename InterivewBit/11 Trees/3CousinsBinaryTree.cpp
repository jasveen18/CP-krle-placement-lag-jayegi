/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Cousins in binary tree
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> res;
    queue<TreeNode*> q;
    if (A == NULL)
        return {};
    if (A->val == B)
        return {};

    q.push(A);
    bool thisLevel = false;

    while (!q.empty()) {
        int n = q.size();

        // If this is the level of cousins
        if (thisLevel) {
            for (int i = 0; i < n; i++) {
                res.push_back(q.front()->val);
                q.pop();
            }

            return res;
        } else {
            for (int i = 0; i < n; i++) {
                TreeNode* curr = q.front(); q.pop();
                if (curr->left and curr->left->val == B) {
                    thisLevel = true;
                    // q.push(curr->left);
                } else if (curr->right and curr->right->val == B) {
                    thisLevel = true;
                    // q.push(curr->right);
                } else {
                    if (curr->left)
                        q.push(curr->left);
                    if (curr->right)
                        q.push(curr->right);
                }
            }
        }

    }

    return {};
}
