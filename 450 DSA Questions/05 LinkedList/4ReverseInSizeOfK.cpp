/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Given a linked list of size N. The task is to reverse every k nodes (where k is an input to the function) in the linked list.
/*
  Node is defined as
    struct node
    {
        int data;
        struct node* next;

        node(int x){
            data = x;
            next = NULL;
        }

    }*head;
*/

// OP OP OP
struct node *reverseLinkedListSizeK(struct node *head, int k) {
	if (head == NULL or head->next == NULL)
		return head;

	int numberOfReversals = 0;
	struct node *curr = head, *slow = NULL, *fast = head;
	struct node *headNode = head;

	while (numberOfReversals < k and fast != NULL) {
		fast = fast->next;

		curr->next = slow;
		slow = curr;
		curr = fast;
		numberOfReversals++;
	}

	if (fast != NULL)
		headNode->next = reverseLinkedListSizeK(fast, k);

	return prev;
}