/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Find diagonal traversal of tree
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void preorder(TreeNode* root, int rank, map<int, vector<int>> &ans) {
	if (root == NULL)
		return;

	ans[rank].push_back(root->val);
	preorder(root->left, rank + 1, ans);
	preorder(root->right, rank, ans);
}

vector<int> Solution::solve(TreeNode* A) {
	vector<int> res;
	map<int, vector<int>> ans;

	preorder(A, 0, ans);

	for (auto it = ans.begin(); it != ans.end(); it++) {
		for (auto el : it->second)
			res.push_back(el);
	}

	return res;
}
