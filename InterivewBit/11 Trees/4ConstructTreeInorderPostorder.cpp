/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Given inorder and postorder traversal of a tree, construct the binary tree.
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* buildMyTree(vector<int> &pro, vector<int> &ino, int start, int end, int &pre, unordered_map<int, int> &mp) {
    // Base Case
    if (start > end or pre >= pro.size())
        return NULL;

    // Now make the Node
    int curr = pro[pre--];
    TreeNode* root = new TreeNode(curr);

    // Inorder pe it lies at
    int inIdx = mp[curr]; // Hash will save O(N) time here.

    root->right = buildMyTree(pro, ino, inIdx + 1, end, pre, mp);
    root->left = buildMyTree(pro, ino, start, inIdx - 1, pre, mp);

    return root;
}

TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    int pre = A.size() - 1;
    unordered_map<int, int> mp;
    for (int i = 0; i < A.size(); i++) {
        mp[A[i]] = i;
    }

    TreeNode *root = buildMyTree(B, A, 0, A.size() - 1, pre, mp);
    return root;
}
