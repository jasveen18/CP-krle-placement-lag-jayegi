/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Find triplet which sum to K in a sorted DLL.
void tripletSumDLL(Node* head, int k) {
	Node* curr = head;
	Node* end = head;

	// Grab the end node
	while (end->next != NULL)
		end = end->next;

	while (curr->next != NULL) {
		Node* low = curr->next;
		Node* high = end;

		while (low != high and high->next != low) {
			int sumHere = curr->data + low->data + high->data;

			if (sumHere < k) {
				low = low->next;
			} else if (sumHere > k) {
				high = high->prev;
			} else {
				cout << curr->data << " " << low->data << " " << high->data << endl;
				low = low->next;
				high = high->prev;
			}
		}
	}

	return;
}