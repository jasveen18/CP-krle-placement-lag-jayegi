/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Do the Level Order Traversal of Binary Tree
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    vector<vector<int>> levelOrder;
    queue<TreeNode*> q;

    if (A == NULL)
        return {};

    q.push(A);
    while (q.empty() == false) {
        int n = q.size();
        vector<int> temp;

        for (int i = 0; i < n; i++) {
            TreeNode* curr = q.front(); q.pop();
            temp.push_back(curr->val);

            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }

        levelOrder.push_back(temp);
    }

    return levelOrder;
}
