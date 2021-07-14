/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Find two elements from bst who sum to B.
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* ascMove(stack<pair<TreeNode*, int>> &st) {
    while (st.size() != 0) {
        TreeNode* curr = st.top().first;
        int status = st.top().second;
        st.pop();

        if (status == 1) {
            status++;
            st.push({curr, status});
            if (curr->left)
                st.push({curr->left, 1});
        } else if (status == 2) {
            status++;
            st.push({curr, status});
            if (curr->right)
                st.push({curr->right, 1});
            return curr;
        }
        else {
            // Nothing
        }
    }

    return NULL;
}

TreeNode* descMove(stack<pair<TreeNode*, int>> &st) {
    while (st.size() != 0) {
        TreeNode* curr = st.top().first;
        int status = st.top().second;
        st.pop();

        if (status == 1) {
            status++;
            st.push({curr, status});
            if (curr->right)
                st.push({curr->right, 1});
        } else if (status == 2) {
            status++;
            st.push({curr, status});
            if (curr->left)
                st.push({curr->left, 1});
            return curr;
        }
        else {
            // Nothing
        }
    }

    return NULL;
}


int Solution::t2Sum(TreeNode* A, int B) {
    TreeNode* start = A;
    TreeNode* end = A;

    stack<pair<TreeNode*, int>> asc;
    stack<pair<TreeNode*, int>> desc;

    asc.push({A, 1});
    desc.push({A, 1});

    start = ascMove(asc);
    end = descMove(desc);

    while (start->val < end->val) {
        if (start->val + end->val == B)
            return 1;
        else if (start->val + end->val < B)
            start = ascMove(asc);
        else
            end = descMove(desc);
    }

    return 0;
}
