/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - BST Iterator, only next
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

stack<pair<TreeNode*, int>> st;
BSTIterator::BSTIterator(TreeNode *root) {
    if (root == NULL)
        return;

    st.push({root, 1});
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
    return !st.empty();
}

/** @return the next smallest number */
int BSTIterator::next() {
    while (st.empty() == false) {
        TreeNode* curr = st.top().first;
        int status = st.top().second;
        st.pop();

        if (status == 1) {
            status++;
            st.push({curr, status});

            if (curr->left)
                st.push({curr->left, 1});
        }

        else if (status == 2) {
            // status++;
            // st.push({curr, status});

            if (curr->right)
                st.push({curr->right, 1});

            return curr->val;
        }

        else {

        }
    }

    return -1;
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
