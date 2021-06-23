/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Write a Program to Move the last element to Front in a Linked List.

Node* moveLastToFirst(Node* head) {
	if (head == NULL or head->next == NULL)
		return;

	Node *curr = head;

	while (curr->next->next != NULL) {
		curr = curr->next;
	}

	curr->next->next = head;
	curr->next = NULL;

	return curr->next;
}