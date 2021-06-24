/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Function to find the data of nth node from the end of a linked list.
int getNthFromLast(Node *head, int n) {
	Node* fast = head;
	Node* curr = head;

	while (fast != NULL and n > 0) {
		fast = fast->next;
		n--;
	}

	if (n != 0)
		return -1;

	while (fast != NULL) {
		curr = curr->next;
		fast = fast->next;
	}

	return curr->data;
}