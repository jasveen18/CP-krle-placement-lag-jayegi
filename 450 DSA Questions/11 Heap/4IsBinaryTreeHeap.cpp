/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Check if binary tree is max-heap.
// 1. Parent -> data > children -> data.
// 2. Complete tree

// Will use a level order traversal to check complete tree
bool isHeap(struct Node * tree) {
	if (tree == NULL)
		return true;

	queue<Node*> q;
	int a = 0;
	int violations = 0;

	q.push(tree);

	while (!q.empty()) {
		int sizeQ = q.size();

		if (sizeQ != pow(2, a))
			violations++;  // Incomplete tree
		if (violations > 1)
			return false;  // Last level ka check hai, wo incomplete reh skta
		a++;

		// Iss level ko pura khaali kr denge ab.
		for (int i = 0; i < sizeQ; i++) {
			Node* curr = q.front();
			if (curr->left) {
				if (curr->left->data > curr->data)
					return false;
				q.push(curr->left);
			}
			if (curr->right) {
				if (curr->right->data > curr->data)
					return false;
				q.push(curr->right);
			}

			q.pop();
		}
	}

	return true;
}