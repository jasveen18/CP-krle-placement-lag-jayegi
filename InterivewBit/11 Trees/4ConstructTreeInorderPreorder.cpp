/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Given preorder and inorder traversal of a tree, construct the binary tree.
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
    int curr = pro[pre++];
    TreeNode * root = new TreeNode(curr);

    // Inorder pe it lies at
    int inIdx = mp[curr]; // Hash will save O(N) time here.

    // int inIdx = start;
    // for(int i=start; i<=end; i++){
    //     if(curr == ino[i]) {
    //         inIdx = i;
    //         break;
    //     }
    // }

    root->left = buildMyTree(pro, ino, start, inIdx - 1, pre, mp);
    root->right = buildMyTree(pro, ino, inIdx + 1, end, pre, mp);

    return root;
}

TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    int pre = 0;
    unordered_map<int, int> mp;
    for (int i = 0; i < B.size(); i++) {
        mp[B[i]] = i;
    }

    TreeNode *root = buildMyTree(A, B, 0, A.size() - 1, pre, mp);
    return root;
}
