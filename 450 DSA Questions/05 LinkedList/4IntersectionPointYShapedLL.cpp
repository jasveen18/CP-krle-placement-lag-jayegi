/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2) {
	// Approach is to create a loop from last node of 2nd List to the head.
	// Then we will use Floyd Warshall to find the first element of the loop.

	Node* curr1 = head1;
	while (curr1->next != NULL)
		curr1 = curr1->next;

	curr1->next = head2;
	Node* res = firstElementOfLoop(head1);

	return res == NULL ? 0 : res->data;
}


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