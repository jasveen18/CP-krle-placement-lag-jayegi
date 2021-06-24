/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Return the starting point of Loop in a LL.
Node* firstElementOfLoop(Node* head) {
	Node* fast = head, *slow = head;

	while (fast != NULL and fast->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;

		if (fast == slow)
			break;
	}

	// If we don't find any loop
	if (slow != fast)
		return NULL;

	// If they both were equal indicating a cycle, then to find the first element hmlog ek pointer ko first pe le jaate and then run again at same speed.
	// You know the mathematical proof too.
	if (slow == fast) {
		slow = head;
		while (slow != fast) {
			slow = slow->next;
			fast = fast->next;
		}
	}

	return slow;
}