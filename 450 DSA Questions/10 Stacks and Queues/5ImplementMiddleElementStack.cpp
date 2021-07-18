/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Design a stack which will support, these operations in O(1) Time ->
// 1. Push
// 2. Pop
// 3. Find middle
// 4. Delete middle

// We can't use array to implement since delete operation won't be O(1)
// We need to move the middle pointer up and down when push and pop is done,
// therefore, doubly linked list is preferred.

class DLLNode {
public:
	int data;
	DLLNode* prev, next;
};

class Stack {
public:
	DLLNode* head; // Top
	DLLNode* middleNode // Mid element
	int count;
};

Stack* createStack() {
	Stack* st = new Stack();
	st->count = 0;
	return st;
}

void push(Stack *st, int val) {
	// Create a new node
	DLLNode* newNode = new DLLNode();
	newNode->data = val;

	// Update the new node bindings
	newNode->prev = NULL;
	newNode->next = st->head;

	// Increase size of stack
	st->count += 1;

	// We will update the mid in 2 cases -
	// 1. Linked list is empty
	// 2. Number of nodes is odd
	if (st->count == 1) {
		st->middleNode = newNode;
	} else {
		st->head->prev = newNode;

		if (!(st->count & 1)) // Update middle when count is even
			st->middleNode = st->middleNode->prev;
	}

	// Update the head of stack (top element)
	st->head = newNode;
}

int pop(Stack *st) {
	// Stack underflow
	if (st->count == 0)
		return;

	// Store details of top
	DLLNode* top = st->head;
	int item = top->data;

	// Update top element
	st->head = top->next;

	// If LL is not empty
	if (st->head != NULL)
		st->head->prev = NULL;

	st->count -= 1;

	// Update mid
	if ((st->count & 1))
		st->mid = st->mid->next;

	return item;
}


int getMiddle(Stack* st) {
	if (st->count == 0)
		return -1;

	return st->middleNode->data;
}


int deleteMiddle(Stack* st) {
	int mid = st->middleNode->data;

	st->middleNode->prev->next = st->middleNode->next;
	st->middleNode->next->prev = st->middleNode->prev;

	delete st->middleNode;
	st->middleNode = st->middleNode->next;

	return mid;
}