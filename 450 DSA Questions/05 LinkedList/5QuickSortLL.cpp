/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Peform Quick Sort in the LL.

struct node* partitionIndex(struct node* head, struct node* tail) {
	node* prev = head, *curr = head->next;
	node* pivot = head;

	while (curr != tail->next) {
		if ()
		}
}


void quickSortRecursive(struct node* head, struct node* tail) {
	// Base Case
	if (head == tail or tail == NULL or head == NULL)
		return;

	// Find the pivot element
	struct node* pivot = partitionIndex(head, tail);

	// Recursive Case
	quickSortRecursive(head, pivot);
	quickSortRecursive(pivot->next, tail);
}


void quickSort(struct node **headRef) {
	node *tail = *headRef;

	// Find the tail
	while (tail->next != NULL)
		tail = tail->next;

	quickSortRecursive(*headRef, tail);
}