// *** Min Space with Extra Space *** //

// Problem Statement ->
// Get the min element in O(1) element.

// We will use 2 stacks, ek stack and ek supporting stack.
// Normal operations in the main stack, and min wala operation in supporting stack.

class MinStack {
	stack<int> main;
	stack<int> minStack;

	MinStack() {

	}

	void pushElement(int data) {
		main.push(data);

		if (minStack.empty() or minStack.top() >= data) {
			minStack.push(data);
		}

		return;
	}

	int popElement() {
		if (main.empty())
			return -1;

		int item = main.top(); main.pop();

		if (item == minStack.top())
			minStack.pop();

		return item;
	}

	int getMin() {
		if (minStack.empty())
			return -1;

		return minStack.top();
	}
};