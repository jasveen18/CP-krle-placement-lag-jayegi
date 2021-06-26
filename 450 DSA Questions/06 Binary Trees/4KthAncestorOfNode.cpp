/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Find the Kth Ancestor of a node. If it doesn't exist then return -1
// Useful info - the binary tree is numbered from 1 to N.

// Approach 1 - BFS
// The idea is to first traverse the binary tree and store the ancestor of each node.
// ith node ka ancestor will be at ancestorArr[i], 2nd ancestor of ith node will be at
// ancestorArr[ancestorArr[i]].

// root node, total nodes, kth anc, target node
int kthAncestorBFS(Node* root, int n, int k, int node) {
	// Make a array to store the ancestory
	int ancestors[n + 1] = {0};

	// Generate the ancestors
	findAncestors(root, ancestors);

	// Find the kth ancestor
	int count = 0; // ancestors visited so far
	while (node != -1) {
		node = ancestors[node];
		count++;

		if (count == k)
			break;
	}

	return node;
}


void findAncestors(Node* root, int ancestors[]) {
	// Root ka ancestor is marked -1
	ancestors[root->data] = -1;

	// Level order traversal to fill ancestors
	queue<Node*> q;
	q.push(root);

	while (!q.empty()) {
		Node* curr = q.front(); q.pop();

		if (curr->left) {
			ancestors[curr->left->data] = curr->data;
			q.push(curr->left);
		}

		if (curr->right) {
			ancestors[curr->right->data] = curr->data;
			q.push(curr->right);
		}
	}
}



// Approach 2 - DFS
// Basic approach was to find the node and then backtrack to kth parent.
// Recursion se hi kr lete hai vaisa
// Node* kthAncestorDFS(Node* root, int node, int &k) {
// 	if (root == NULL)
// 		return NULL;

// 	Node*
// }