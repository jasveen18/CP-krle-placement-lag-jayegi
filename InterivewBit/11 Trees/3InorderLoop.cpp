/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::inorderTraversal(TreeNode* A) {
    vector<int> res;
    stack<pair<TreeNode*, int>> st;

    if (A == NULL)
        return {};

    st.push({A, 1});

    while (!st.empty()) {
        TreeNode* curr = st.top().first;
        int status = st.top().second;
        st.pop();

        if (status == 1) {
            // Preorder
            status++;
            st.push({curr, status});
            if (curr->left)
                st.push({curr->left, 1});
        } else if (status == 2) {
            // Inorder
            res.push_back(curr->val);

            status++;
            st.push({curr, status});
            if (curr->right)
                st.push({curr->right, 1});
        } else {
            // Post order, do nothing
        }
    }

    return res;
}
