/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Get the max from combination of nodes such that no two nodes are adjacent.
// By adjacent meaning, direct childre.

// Approach 1 -
// DP + Trees
// Inclusion, Exclusion principle of DP that whether to include this node in our answer or not.

int getMaxSumNode(Node* root) {
	if (root == NULL)
		return 0;

	// DP Yahi hai, ki iss node tk I got this sum.
	map<Node*, int> dp;
	return getMaxSumHelper(root, dp);
}


// Ye main DP Top Down method hoga
int getMaxSumHelper(Node* root, map<Node*, int> &dp) {
	// Base Case -
	if (root == NULL)
		return 0;

	// Look up the dp table.
	if (dp.find(root) != dp.end())
		return dp[root];

	// Include this node.		and take the sum of this node's grand childre, since children ko ni le skte.
	int includeCase = root->data + sumOfGrandChildren(root, dp);

	// Exclude this case, phir toh children ko le skte hai
	int excludeCase = getMaxSumHelper(root->left, dp) + getMaxSumHelper(root->right, dp);

	// Take the max sum
	dp[root] = max(includeCase, excludeCase);
	return dp[root];
}


// Function to get the sum of grand children (smaller subprob)
int sumOfGrandChildren(Node* root, map<Node*, int> &dp) {
	int sum = 0;

	// Get max sum from left grand children
	if (root->left) {
		sum += getMaxSumHelper(root->left->left, dp) + getMaxSumHelper(root->left->right, dp);
	}

	// Get max sum right grand children
	if (root->right) {
		sum += getMaxSumHelper(root->right->left, dp) + getMaxSumHelper(root->right->right, dp);
	}

	return sum;
}


// Approach 2 -
// Using pairs.
// The concept is same, here the difference is we are storing include in pair.first and exlude case in pair.second.

int getMaxSumNode(Node *root) {
	pair<int, int> res = maxSumHelperPairs(root);
	return max(res.first, res.second);
}

// pair.first means included, pair.second means not included.
pair<int, int> maxSumHelperPairs(Node* root) {
	if (root == NULL) {
		pair<int, int> sum(0, 0);
		return sum;
	}

	pair<int, int> leftSum = maxSumHelperPairs(root->left);
	pair<int, int> rightSum = maxSumHelperPairs(root->right);
	pair<int, int> sumHere;

	// Include case - means leftSum and rightSum ni aayega
	sumHere.first = leftSum.second + rightSum.second + root->data;

	// Exclude case - means leftsum and right sum hi aayega bss
	sumHere.second = max(leftSum.first, leftSum.second) + max(rightSum.first, rightSum.second);

	return sumHere;
}