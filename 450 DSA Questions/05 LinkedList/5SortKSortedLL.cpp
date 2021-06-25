/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Given a doubly linked list containing n nodes, where each node is at most k away from its target position in the list. The problem is to sort the given doubly linked list.

// Approach 1 - Insertion Sort method.
// O(n*k) time | O(1) space
// We will insert the elements at the correct place.
// For the first element, we will see the least num in 'k' elements phir waha pe place kr denge.
Node* sortKSortedLL(Node* head, int k) {
	if (head == NULL or head->next == NULL)
		return head;

	for (Node* curr = head->next; curr != NULL; curr = curr->next) {
		Node* j = curr;

		while (j->prev != NULL and j->data < j->prev->data) {

		}
	}
}