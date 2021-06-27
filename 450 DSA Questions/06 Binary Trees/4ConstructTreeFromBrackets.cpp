/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Construct Tree From Brackets
// Input : "4(2(3)(1))(6(5))"
// Output : 4 2 3 1 6 5
// Explanation :
//            4
//          /   \
//         2     6
//        / \   /
//       3   1 5

// Idea is to insert the root node and then search for opening and closing bracket for left and right nodes.
Node* treeFromString(string brackets, int si, int ei) {	// str, 0, str.size()-1
	if (si > ei)
		return NULL;

	// New node
	Node* root = new Node(brackets[si] - '0');
	int index = -1; // to find the index of starting and ending

	// If next char is '(' find it's complementing ')'.
	if (si + 1 <= ei and brackets[si + 1] == '(')
		index = findComplement(brackets, si + 1, ei);

	if (index != -1) {
		// If index is found, now make the childre nodes
		// si+2 so that bracket ignore ho jaaye, index-1 so that end bracket ignore no jaaye
		root->left = treeFromString(brackets, si + 2, index - 1);

		// index + 2, because index = ')', index+1 = '(', isliye index+2 = value
		// ei - 1 kyunki uske corresponding bracker hata dere hai end se.
		root->right = treeFromString(brackets, index + 2, ei - 1);
	}

	return root;
}


// We will use stack to find the complement
int findComplement(string str, int si, int ei) {
	if (si > ei)
		return -1;

	stack<char> s;
	for (int i = si; i <= ei; i++) {
		if (str[i] == '(')
			s.push[str[i]];

		else if (str[i] == ')') {
			if (s.top() == '(') {
				s.pop();

				// If we find the stack to be empty at any point, voi required index hai.
				if (s.empty())
					return i;
			}
		}
	}
	return -1;
}