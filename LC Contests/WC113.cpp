// 1. 949. Largest Time for Given Digits
string largestTimeFromDigits(vector<int>& arr) {
	int resh = 0, resm = 0;
	vector<int> res;
	int count = 24;

	sort(arr.begin(), arr.end());

	for (int i = 0; i < 24; i++)  {

		int h = arr[0] * 10 + arr[1];
		int m = arr[2] * 10 + arr[3];

		// Check validity
		if (h <= 23 and m < 60) {
			// Check if greater than ans
			if (resh * 60 + resm <= h * 60 + m) {
				resh = h;
				resm = m;
				res = arr;
			}
		}


		next_permutation(arr.begin(), arr.end());
	}

	if (res.size() == 0)
		return "";

	string strRes = to_string(res[0]) + to_string(res[1]) + ":" + to_string(res[2]) + to_string(res[3]);
	return strRes;
}

// 2.951. Flip Equivalent Binary Trees
bool flipEquiv(TreeNode* root1, TreeNode* root2) {
	if (root1 == NULL and root2 == NULL)
		return true;

	if (root1 == NULL or root2 == NULL)
		return false;

	if (root1->val != root2->val)
		return false;

	bool one = flipEquiv(root1->left, root2->left) and flipEquiv(root1->right, root2->right);
	bool two = flipEquiv(root1->left, root2->right) and flipEquiv(root1->right, root2->left);

	return one | two;
}


// 3.950. Reveal Cards In Increasing Order
vector<int> deckRevealedIncreasing(vector<int>& deck) {
	int n = deck.size();
	sort(deck.begin(), deck.end());

	// Positions
	list<int> l(n);
	iota(l.begin(), l.end(), 0);

	vector<int> res(n);
	auto lp = l.begin();

	for (int i = 0, skip = 0; l.empty() == false; skip = !skip) {
		if (lp == l.end()) lp = l.begin();

		if (skip) ++lp;

		else {
			res[*lp] = deck[i++];
			l.erase(lp++);
		}
	}

	return res;
}