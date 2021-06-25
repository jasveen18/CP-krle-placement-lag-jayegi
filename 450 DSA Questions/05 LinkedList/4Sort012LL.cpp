/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Given a linked list with only three distince values 0, 1, 2. Sort it.
// O(N) Time | O(1) Space
Node* sort012LL(Node* head) {
	Node* curr = head;
	Node* zero = NULL;
	Node* one = NULL;
	Node* two = NULL;

	Node* zeroTravesal = NULL;
	Node* oneTravesal = NULL;
	Node* twoTravesal = NULL;

	while (curr != NULL) {
		fast = curr->next;

		// Check the value of data
		if (curr->data == 0) {
			if (zero == NULL) {
				zero = curr;
				zeroTravesal = zero;
			} else {
				zeroTravesal->next = curr;
				zeroTravesal = zeroTravesal->next;
			}
		} else if (curr->data == 1) {
			if (one == NULL) {
				one = curr;
				oneTravesal = one;
			} else {
				oneTravesal->next = curr;
				oneTravesal = oneTravesal->next;
			}
		} else if (curr->data == 2) {
			if (two == NULL) {
				two = curr;
				twoTravesal = two;
			} else {
				twoTravesal->next = curr;
				twoTravesal = twoTravesal->next;
			}
		}

		// Move Curr ahead
		curr = fast;
	}

	// Now we need to join all three of them, first, let's make their end as null.
	if (zero)
		zeroTravesal->next = NULL;
	if (one)
		oneTravesal->next = NULL;
	if (two)
		twoTravesal->next = NULL;

	vector<Node*> mergedLL;
	// Let's join zero and one first
	mergedLL = joinTwoLL(zero, zeroTravesal, one, oneTravesal);
	zero = mergedLL[0];
	zeroTravesal = mergedLL[1];

	// Let's join previous LL and two
	mergedLL = joinTwoLL(zero, zeroTravesal, two, twoTravesal);
	zero = mergedLL[0];
	zeroTravesal = mergedLL[1];

	return zero;
}


vector<Node*> joinTwoLL(Node* head1, Node*tail1, Node* head2, Node* tail2) {
	if (!head2)
		return {head1, tail1};

	if (!head1)
		return {head2, tail2};

	tail1->next = head2;
	return {head1, tail2};
}