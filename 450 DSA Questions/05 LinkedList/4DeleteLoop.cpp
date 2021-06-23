/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Delete the loop in the LL.

void removeLoopLL(Node* head) {
	Node* fast = head, *slow = head;

	while (fast != NULL and fast->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;

		if (fast == slow)
			break;
	}

	// If we don't find any loop
	if (fast == NULL or fast->next == NULL)
		return;

	// If we find the loop, we need to go to the first element of the loop.
	if (slow == head) {
		while (slow->next != head)
			slow = slow->next;
		slow->next = NULL;
	}

	// If they both were equal indicating a cycle, then to find the first element hmlog ek pointer ko first pe le jaate and then run again at same speed.
	// You know the mathematical proof too.
	if (slow == fast) {
		slow = head;
		while (slow->next != fast->next) {
			slow = slow->next;
			fast = fast->next;
		}

		fast->next = NULL;
	}


	return;
}