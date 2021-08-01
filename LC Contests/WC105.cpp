// 1. 917. Reverse Only Letters
string reverseOnlyLetters(string s) {
	string letters = "";
	queue<pair<char, int>> inc;

	for (int i = 0; i < s.size(); i++) {
		if ((s[i] >= 'a' and s[i] <= 'z') or (s[i] >= 'A' and s[i] <= 'Z'))
			letters += s[i];
		else
			inc.push({s[i], i});
	}

	reverse(letters.begin(), letters.end());

	string res = "";
	int j = 0;
	for (int i = 0; i < s.size(); i++) {
		if (inc.front().second != i) {
			res += letters[j++];
		} else {
			res += inc.front().first;
			inc.pop();
		}
	}

	return res;
}



// 3. Complete Binary Tree Inserter
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class CBTInserter {
private:
	int insert(TreeNode* root, int v, bool &ins, int maxh, int h) {
		if (ins)
			return -1;
		// Check for both nodes
		if (root->left == NULL and root->right == NULL and h == maxh)
			return -1;

		if (root->left == NULL) {
			root->left = new TreeNode(v);
			ins = true;
			return root->val;
		}

		if (root->right == NULL) {
			root->right = new TreeNode(v);
			ins = true;
			return root->val;
		}

		int left = insert(root->left, v, ins, maxh, h + 1);
		int right = insert(root->right, v, ins, maxh, h + 1);

		if (left != -1)
			return left;
		if (right != -1)
			return right;

		return -1;
	}

public:
	TreeNode* root;
	CBTInserter(TreeNode* root) {
		this->root = root;
	}

	int insert(int v) {
		// 2 case banate hai,
		// 1. If it is complete fully (filled)
		// 2. If koi ek level pe missing hai toh vaha daal dena. (height bhi maintain kr lo)
		// Try on second case first, if that fails then left most pe insert kr denge

		int maxh = 0;
		TreeNode* temp = root;
		while (temp->left != NULL) {
			temp = temp->left;
			maxh++;
		}

		bool inserted = false;
		TreeNode* curr = root;
		int res = insert(curr, v, inserted, maxh, 0);

		if (inserted)
			return res;

		// Now first case since it is a completely filled tree
		curr = root;
		while (curr->left != NULL)
			curr = curr->left;

		curr->left = new TreeNode(v);
		return curr->val;
	}

	TreeNode* get_root() {
		return this->root;
	}
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */