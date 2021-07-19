/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Given sorted list, make BST.
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

TreeNode* makeBST(vector<int> &res, int start, int end) {
    if (start > end)
        return NULL;

    int mid = start + (end - start) / 2;

    TreeNode* root = new TreeNode(res[mid]);

    root->left = makeBST(res, start, mid - 1);
    root->right = makeBST(res, mid + 1, end);

    return root;
}

TreeNode* Solution::sortedListToBST(ListNode* A) {
    vector<int> res;

    ListNode* curr = A;
    while (curr != NULL) {
        res.push_back(curr->val);
        curr = curr->next;
    }

    return makeBST(res, 0, res.size() - 1);
}
