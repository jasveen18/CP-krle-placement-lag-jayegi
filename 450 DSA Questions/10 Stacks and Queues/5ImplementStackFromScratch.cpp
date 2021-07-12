/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Implement Stack from scratch.

class CustomStack {
private:
	int maxSize;
	vector<int> st;
	int top;

public:
	CustomStack(int size) {
		maxSize = size;
		top = -1;
		st = vector<int> (size);
	}

	void push(int x) {
		st[++top] = x;
	}

	int pop() {
		return st[top--];
	}

	int peek() {
		return st[top];
	}

	bool isEmpty() {
		return top == -1;
	}

	bool isFull() {
		return top == maxSize - 1;
	}
};