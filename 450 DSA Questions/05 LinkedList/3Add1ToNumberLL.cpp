/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Add '1' to the number represented by Linked List

Node* reverseList(Node* head) {
	if (head == NULL or head->next == NULL)
		return head;

	Node* subProb = reverseList(head->next);
	head->next->next = head;
	head->next = NULL;

	return subProb;
}


Node* addOne(Node *head) {
	Node* curr = head;

	// Reverse the LL first
	Node* revList = reverseList(curr);
	curr = revList;

	// Now we can add one to the first element
	int carry = 1;

	// Take care of 9s
	while (curr != NULL and carry != 0) {
		int sum = curr->data + carry;

		curr->data = (sum) % 10;
		carry = (sum) / 10;

		curr = curr->next;
	}

	// For the case of '999', we need to add a new node -> 1000
	if (carry) {
		curr = revList;
		while (curr->next != NULL)
			curr = curr->next;
		// Add a new node
		curr->next = new Node(1);
	}

	return reverseList(revList);
}