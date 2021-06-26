/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Convert a given Binary Tree to Doubly Linked List.
// left will prev pointer
// right will be next pointer.

// Bss 2 pointers le lena hai and aage badhte jaana hai jaise LL banate hai.
void treeToDLL(Node* root, Node* &head, Node* &tail) {
	// In order traversal
	if (root == NULL)
		return;

	treeToDLL(root->left, head, tail);

	// Operations here
	// If we have not encountered anything yet.
	if (head == NULL) {
		head = root;
		tail = root;
	} else {	// Tail ko aage badhate jao
		tail->right = root;
		tail->right->left = tail;
		tail = tail->right;
	}

	treeToDLL(root->right, head, tail);
}


Node * bToDLL(Node *root) {
	Node* head = NULL;
	Node* tail = NULL;

	treeToDLL(root, head, tail);
	return head;
}