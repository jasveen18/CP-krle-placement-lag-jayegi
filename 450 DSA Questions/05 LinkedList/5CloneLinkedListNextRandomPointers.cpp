/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Clone a linked list with next and random pointers
Node* copyRandomList(Node* head) {
	if (head == NULL)
		return head;

	// Create a mapping of cloned list using original list
	// Isme kya hora hai ki -> Original list with random pointer was 1->2->3->4->NULL
	// Mapping ke baad we have, 1->1->2->2->3->3->4->4->NULL.
	// Ek new list banaye hai only based on next, new nodes are at even places.
	Node* curr = head;
	while (curr != NULL) {
		Node* newNode = new Node(curr->val);
		newNode->next = curr->next;
		curr->next = newNode;
		curr = newNode->next;
	}

	// Assign Random Pointers
	// Now random pointers ko assign krre hai based on
	curr = head;
	while (curr != NULL) {
		if (curr->random != NULL) {
			// 1->1 (mtlb even (duplicate) wale ka random)
			//                     3->3, random node ka duplicate wale pe.
			curr->next->random = curr->random->next;
		}

		curr = curr->next->next;
	}

	// Restore the original linked list
	Node *newHead = head->next;
	Node *newCurr = newHead;

	curr = head;

	while (curr) {
		curr->next = newCurr->next;

		if (newCurr->next)
			newCurr->next = curr->next;

		curr = curr->next;
		newCurr = newCurr->next;
	}

	return newHead;
}




// Approach 2 -
RandomListNode* Solution::copyRandomList(RandomListNode* A) {
	unordered_map<RandomListNode*, RandomListNode*> mp;
	RandomListNode* curr = A;

	while (curr) {
		mp[curr] = new RandomListNode(curr->label);
		curr = curr->next;
	}

	curr = A;
	while (curr) {
		mp[curr]->next = mp[curr->next];
		mp[curr]->random = mp[curr->random];
		curr = curr->next;
	}

	return mp[A];
}
