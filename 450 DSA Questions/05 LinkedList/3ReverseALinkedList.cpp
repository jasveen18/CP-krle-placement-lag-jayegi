/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Reverse a LL, in place
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


// Iterative Process
ListNode* reverseLinkedListIterative(ListNode* head) {
	// Empty or only one element
	if (head == NULL or head->next == NULL)
		return head;

	ListNode *slow = NULL, *fast = head, *curr = head;

	// Traverse over all the nodes and change the connectings
	while (fast != NULL) {
		fast = fast->next;

		// Change bindings
		curr->next = slow;
		slow = curr;
		curr = fast;
	}

	return slow;
}


// Recursive Process
ListNode* reverseLinkedListRecursive(ListNode *head) {
	// Base Case
	if (head == NULL or head->next == NULL)
		return head;

	// Recursive Case
	ListNode* resSubProb = reverseLinkedListRecursive(head->next);
	head->next->next = head;
	head->next = NULL;

	return resSubProb;
}