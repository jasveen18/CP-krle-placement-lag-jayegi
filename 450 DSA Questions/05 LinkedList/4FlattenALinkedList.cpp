/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Flatten a Linked List given by next and bottom pointer.

// Input:
// 5 -> 10 -> 19 -> 28
// |     |     |     |
// 7     20    22   35
// |           |     |
// 8          50    40
// |                 |
// 30               45
// Output:  5-> 7-> 8- > 10 -> 19-> 20->
// 22-> 28-> 30-> 35-> 40-> 45-> 50.

Node* merge2LL(Node* l1, Node* l2) {
	if (!l1)
		return l2;
	if (!l2)
		return l1;

	if (l1->data < l2->data) {
		l1->bottom = merge2LL(l1->bottom, l2);
		return l1;
	} else {
		l2->bottom = merge2LL(l1, l2->bottom);
		return l2;
	}
}


Node* flattenLL(Node* root) {
	if (root == NULL or root->next == NULL)
		return root;

	root->next = flattenLL(root->next);
	root = merge2LL(root, root->next);

	return root;
}