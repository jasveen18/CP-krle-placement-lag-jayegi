/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Given a singly linked list, remove all the nodes which have a greater value on its following nodes.

// Reverse the LL
Node* reverseList(Node *head) {
	// Base Case
	if (head == NULL or head->next == NULL)
		return head;

	// Recursive Case
	Node* resSubProb = reverseList(head->next);
	head->next->next = head;
	head->next = NULL;

	return resSubProb;
}


Node* deleteFromRight(Node* head) {
	if (head == NULL or head->next == NULL)
		return head;

	Node* curr = head;

	// Reverse and then traverse krenge, if last seen max se kam hua toh ni include krenge
	curr = reverseList(curr);
	Node* revHead = curr;
	int lastMax = 0;

	lastMax = curr->data;
	while (curr->next != NULL) {
		while (curr->next != NULL and curr->next->data < lastMax) {
			curr->next = curr->next->next;
		}

		if (curr->next) {
			lastMax = curr->next->data;
			curr = curr->next;
		}
	}

	return reverseList(revHead);
}