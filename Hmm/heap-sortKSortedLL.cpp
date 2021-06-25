// *** Sorted a array which is K sorted *** //
// means nearly sorted

// Problem Statement - The array is K sorted, now sort it.
// By k sorted I mean -
// 6 5 3 2 8 10 9 --> array
// 0 1 2 3 4 5  6 --> index
// Jo element index 0 pe hota wo kahi (0+k) or (0-k) ke beech m lie krega.

// Mtlb the correct element at index idx would lie at some index between (idx-k) to (idx+k).

// Naive Approach toh sidhe sort kr do merge sort se. O(NLogN) use krke.

// Heap wali approach -
// For index 0, I don't need to see peeche, I'll just look till 'k' ki sbse chota kaun hai?
// Usko laga dunga index 0 pe. Phir aage jayenge and idx 0 wale element ko heap pe daal denge.

// O(N Log K) pe ho jayega apna kaam.

void sortNearSortedArr(int *arr, int n, int k) {
	priority_queue<int, vector<int>, greater<int>> pq;
	int j = 0;
	// Now insert into PQ
	for (int i = 0; i < n; i++)  {
		pq.push(arr[i]);
		if (pq.size() > k) {
			arr[j++] = pq.top();
			pq.pop();
		}
	}

	while (!pq.empty()) {
		arr[j++] = pq.top(); pq.pop();
	}
}