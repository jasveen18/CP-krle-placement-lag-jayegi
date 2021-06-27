/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Merge 2 Balanced BST

// Approach 1 -
// Take one tree and insert all the nodes of the second tree.
// An AVL Tree or Red Black Tree will take O(Log N) for insertion.
// Therefore, T - O(N Log (M + N - 1))

// Approach 2-
// Store the values of both the list in array, using inorder traversal.
// Merge the 2 sorted arrays.
// Create a new tree using them.
// T - O(N + M) | S - O(N + M)

// Approach 3 -
// 1. Change both the trees into doubly linked list.
// 2. Merge the 2 doubly linked list
// 3. Change the doubly linked list back to original tree.
// T - O(N + M) | S - O(1)

// Code of approach 3 -

// Tree -> int data, Node* left, Node* right
// DLL ke lie left is prev, right is next


// Convert a tree to DLL
void convertToDoubleLinkedList(Node* root, Node* &head, Node* tail) {
	if (root == NULL)
		return;

	convertToDoubleLinkedList(root->left, head, tail);

	if (head == NULL) {
		head = root;
		tail = root;
	} else {
		tail->right = root;
		tail->right->left = tail;
		tail = tail->right;
	}

	convertToDoubleLinkedList(root->right, head, tail);
}


// Merge 2 linked lists
Node* merge2DoublyLinkedList(Node* l1, Node *l2) {
	if (l1 == NULL)
		return l2;
	if (l2 == NULL)
		return l1;

	if (l1->data < l2->data) {
		l1->right = merge2DoublyLinkedList(l1->right, l2);
		if (l1->right)
			l1->right->left = l1;
		return l1;
	} else {
		l2->right = merge2DoublyLinkedList(l1, l2->right);
		if (l2->right)
			l2->right->left = l2;
		return l2;
	}
}


// Construct the tree from given DLL.
// 1. Count the number of nodes.
// 2. Recursively call for n/2 for left and right subtrees
// O(N) operation
int countNodes(Node* head) {
	int count = 0;
	while (head) {
		head = head->next;
		count++;
	}
	return count;
}


Node* sortedListToBST(Node* head) {
	int n = countNodes(head);

	return constructBSTFromDLL(&head, n);
}


Node* constructBSTFromDLL(Node **head, int n) {
	// Base Case
	if (n <= 0)
		return NULL;

	Node* leftSubtree = constructBSTFromDLL(head, n / 2);
	Node* root = *head;

	// update bindings
	root->left = leftSubtree;

	// Keep moving, so that by the time we reach here, middle node pe honge.
	*head = (*head)->next;


	Node* rightSubtree = constructBSTFromDLL(head, n - (n / 2) - 1);
	root->right = rightSubtree;

	return root;
}