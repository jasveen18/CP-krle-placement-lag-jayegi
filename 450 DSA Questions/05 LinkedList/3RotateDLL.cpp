/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Rotate a DLL by n nodes.
Node* rotateDLLbyN(Node* head, int n) {
	if (head == NULL or n == 0)
		return head;

	Node* curr = head;
	int count = 1;

	// Traverse till the nth node
	while (curr != NULL and count < n) {
		curr = curr->next;
		count++;
	}

	// Check if n > size, PS. ask if we have rotate by n times, toh phir (n%size) krenge.
	if (curr == NULL)
		return;

	Node* nthNode = curr;

	// Reach the end of the list to make the connection
	while (curr->next != NULL)
		curr = curr->next;

	curr->next = head;  // Connect end ka next to head
	curr->next->prev = curr; // Connect head ka prev to end

	// Now new head
	Node* resHead = nthNode->next;
	nthNode->next = NULL; // This will be the last node now.

	return resHead;
}