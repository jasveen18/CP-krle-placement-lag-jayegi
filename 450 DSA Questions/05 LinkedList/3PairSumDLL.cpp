/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Find pairs which sum to k in a sorted DLL
void pairSumDLL(Node* head, int k) {
	Node* start = head;
	Node* end = head;

	// Take this to the end of DLL
	while (end->next != NULL)
		end = end->next;

	// Smaller or equal sign jab tk ni hoga.
	while (start != end and end->next != start) {
		if (first->data + second->data < k)
			first = first->next;
		else if (first->data + second->data > k)
			second = second->prev;
		else {
			cout << first->data << " " << second->data << endl;
			first = first->next;
			second = second->prev;
		}
	}

	return;
}