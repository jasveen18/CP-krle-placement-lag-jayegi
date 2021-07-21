/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Implement a circular queue

class Queue {
	int rear, front;

	int size;
	int *arr;

public:
	Queue(int s) {
		size = s;
		arr = new int[s];
		front = rear = -1;
	}

	void enqueue(int item) {
		// If size is full ->
		if ((front == 0 and rear == size - 1) or (rear == (front - 1) % (size - 1)))
			return;

		// First element
		if (front == -1) {
			front = rear = 0;
			arr[rear] = item;
			return;
		}

		// Circularly aage aa gye because size is not full yet, as front is not zero.
		if (rear == size - 1 and front != 0) {
			rear = 0;
			arr[rear] = item;
			return;
		}

		// Else insert normally
		arr[++rear] = item;
		return;
	}

	int dequeue() {
		// If empty
		if (front == -1)
			return -1;

		int item = arr[front];
		arr[front] = -1;

		// If first element ko hi pop krna hai
		if (front == rear) {
			front = -1;
			rear = -1;
		}

		// If last element ko pop krre hai toh phir wapis se zero pe aa jao
		else if (front == size - 1) {
			front = 0;
		}

		// Normal
		else {
			front++;
		}

		return data;
	}
}