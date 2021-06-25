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

	priority_queue<Node*, vector<Node*>, compare> pq;
	Node* newHead = NULL, *curr;

	// Push the first 'k' nodes into the PQ
	for (int i = 0; head != NULL and i <= k; i++) {
		pq.push(head);
		head = head->next;
	}

	while (!pq.empty()) {
		if (newHead == NULL) {
			newHead = pq.top();
			newHead->prev = NULL;
			curr = newHead;
		} else {
			curr->next = pq.top();
			curr->next->prev = curr;
			curr = curr->next;
		}

		pq.pop();

		if (head == NULL) {
			pq.push(head);
			head = head->next;
		}
	}

	curr->next = NULL;

	return newHead;
}

struct compare {
	bool operator()(Node *a, Node* b) {
		return b->data > a->data;
	}
}