/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Implement k stacks efficiently.

// 1. We can divide the array into n/k parts and then implement it.
// But, this may lead to overflow even when space is available.

// 2. Efficient approach ->

// We will maintain 2 arrays,
// One (size k) to store the index of the top element of each stack.
// Two (size n) to store the next element.

class kStacks {
	vector<int> arr; // size n, actual values (here, instead of int it can be objects also, which will make the other two arrays look space optimized as they will be int)
	vector<int> top; // size k, top values of each stack
	vector<int> next; // size n, next entry in all stacks

	int n, k;
	int free; // to store the beginning index of free list

public:
	// Constructor to initialize spaces and mark arrays
	kStacks(int n, int k) {
		this->n = n;
		this->k = k;

		arr = vector<int> (n, 0);
		top = vector<int> (k, -1);
		next = vector<int> (n);

		// Mark all spaces as free
		for (int i = 0; i < n - 1; i++)
			next[i] = i + 1;
		next[n - 1] = -1; // End of stack, free = -1 ho jayega at the end

		// Free will be zero to mark the first index is free to use
		free = 0;
	}

	// To check space is available
	bool isFull() {
		return free == -1;
	}


	// Check for element present for stack number -> sn
	bool isEmpty(int sn) {
		return top[sn] = -1;
	}

	// Function to push the element into stack number -> sn
	void push(int item, int sn) {
		if (isFull())
			return;

		// Take the current free position and update free for next
		int i = free;
		free = next[i];

		// Update next of top and top for stack no -> sn
		next[i] = top[sn];
		top[sn] = i;

		// Put the actual item into arr
		arr[i] = item;
	}


	// Function to pop the top element from stack number -> sn
	int pop(int sn) {
		if (isEmpty(sn))
			return -1;

		int i = top[sn];

		top[sn] = next[i]; // Store next of previous top

		next[i] = free; // Update next and free
		free = i;

		return arr[i];
	}
};