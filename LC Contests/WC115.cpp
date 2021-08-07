// 1.958. Check Completeness of a Binary Tree
bool isCompleteTree(TreeNode* root) {
	vector<vector<int>> level;
	if (root == NULL)
		return true;

	queue<TreeNode*> q;
	q.push(root);
	int l = 0;


	while (q.empty() == false) {
		int size = pow(2, l);
		vector<int> c;
		for (int i = 0; i < size; i++) {
			TreeNode* curr = q.front(); q.pop();

			if (curr == NULL) {
				c.push_back(-1);
				continue;
			}

			c.push_back(curr->val);
			q.push(curr->left);
			q.push(curr->right);
		}

		level.push_back(c);
	}

	// Now we can iterate through the list and find any null values
	bool done = false;
	for (int i = 0; i < level.size(); i++) {
		for (int j = 0; j < level[i].size(); j++) {
			if (level[i][j] >= 1 and done)
				return false;
			if (level[i][j] == -1)
				done = true;
		}
	}

	return true;
}


// 2. 957. Prison Cells After N Days
vector<int> prisonAfterNDays(vector<int>& cells, int n) {

	vector<vector<int> >res;

	int cycle = (n % 14) == 0 ? (14) : (n % 14);

	for (int i = 0; i < cycle; i++) {
		vector<int> curr(cells.begin(), cells.end());
		for (int i = 1; i < cells.size() - 1; i++) {
			if (cells[i - 1] == cells[i + 1])
				curr[i] = 1;
			else
				curr[i] = 0;
		}

		curr[0] = 0; curr[cells.size() - 1] = 0;
		cells = curr;
		res.push_back(curr);
	}

	if (res.size() == 0)
		return cells;
	return res[res.size() - 1];
}