/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Implement a queue from scratch

class CustomQueue {
private:
	int capacity;
	int front, rear, size;
	vector<int> q;

public:
	CustomQueue(int capacity) {
		this->capacity = capacity;
		q = vector<int> (capacity);
		front = -1;
		size = 0;
		rear = -1;
	}

	void enqueue(int x) {
		// If empty
		if (rear == -1) {
			front = 0;
		}

		q[++rear] = x;
		size = size + 1;
	}

	int dequeue() {
		if (size <= 0) return INT_MIN;

		size = size - 1;
		return q[front--];
	}

	int peek() {
		return q[front];
	}

	bool isEmpty() {
		return size == 0;
	}

	bool isFull() {
		return size == capacity;
	}
};