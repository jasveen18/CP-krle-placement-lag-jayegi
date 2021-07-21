/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Given a queue of integers of even length, rearrange the elements by interleaving the first half of the queue with the second half of the queue.

// Only a stack can be used as an auxiliary space.


void interleaveQueue(queue<int> &q) {
	if (q.size() & 1)
		return;

	int n = q.size();
	int half = n / 2;

	stack<int> st;

	// Push first half elements into the stack
	// queue:16 17 18 19 20, stack: 15(T) 14 13 12 11
	for (int i = 0; i < half; i++) {
		st.push(q.front());
		q.pop();
	}

	// Enqueue back the stack elements
	// queue: 16 17 18 19 20 15 14 13 12 11
	while (st.empty() == false) {
		q.push(s.top());
		s.pop();
	}

	// Dequeue the first half elements of queue
	// and enqueue them back
	// queue: 15 14 13 12 11 16 17 18 19 20
	for (int i = 0; i < half; i++) {
		q.push(q.front());
		q.pop();
	}

	// Again push the first half into stack
	// queue: 16 17 18 19 20, stack: 11(T) 12 13 14 15
	for (int i = 0; i < half; i++) {
		st.push(q.front());
		st.pop();
	}

	// Now, we can interleave both
	// queue: 11 16 12 17 13 18 14 19 15 20
	while (st.empty() == false) {
		q.push(st.top());
		st.pop();

		q.push(q.front());
		q.pop();
	}

	return;
}