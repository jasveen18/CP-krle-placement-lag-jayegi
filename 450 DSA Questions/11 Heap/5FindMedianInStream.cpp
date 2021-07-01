/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Find the median in a stream of numbers.
/*
Idea is to use two priority_queue one acting as min heap and other acting as max heap
Firstly median of an array is its central element if size is odd else sum of middle elements
in case of even elemnts.
So we will store all the numbers lesser than a number in Max heap and all number greater
than a number in Min heap
eg 1>. 5 6 7 8 9
:We start from 5 we put it in Max Heap and median=5
:Then comes 6 since 6 is greater than 5 we put it in Min Heap median=(5+6)/2
:Then comes 7 since it is greater than 5 we put it too in Min heap but size of min heap
should be one less than or equal to max heap. so we shift 6 from min to max heap.
now max heap = 6 5 min heap = 7 median=6
:Then comes 8 since 8>6 we put in Min heap. median=(6+7)/2
:Then comes 9 since 9>6 we put it in Min heap but min_heap.size>max_heap.size so we shift
7 from min heap to max heap. Now min_heap= 7 6 5 max_heap =8 9 median=7

eq 2>. 5 4 3 2 1
:We start from 5 we put it in Max Heap and median=5
:Then comes 4 since 4<5 we put it into Max heap but as Max_heap.size()-min_heap.size()==2
we shift top element from max heap to min heap now Max heap= 4 min heap=5 median=(4+5)/2
:Then comes 3 since 3<4 we put it into max heap . median= 4
: now 2 since 2<4 we put it into max heap but size of max heap>min heap+2 therefore we shift
4 from max to min now Max heap=3 2 Min heap= 4 5 median (3+4)/2
: Then comes 1 we since 1<3 we put it into max heap median = 3
*/


class ReturnMedian {
private:
	priority_queue<int> maxHeap; // to store the smaller elements
	priority_queue<int, vector<int>, greater<int>> minHeap; // to store the larger elements
	double median;

public:
	// Function to insert one number in heap
	void insertHeap(int &x) {
		// First element ispe jayega, odd len ke lie max heap lere hai
		if (maxHeap.size() == 0) {
			maxHeap.push(x);
			getMedian();
		}
		// If the element is greater toh min heap pe daalo and balance them
		else if (x > maxHeap.top()) {
			minHeap.push(x);
			balanceHeaps();
			getMedian();
		}
		// If the element is smaller toh max heap pe daalo and balance them
		else {
			maxHeap.push(x);
			balanceHeaps();
			getMedian();
		}
	}

	// Function to balance the heaps
	void balanceHeaps() {
		// Balance krna hai kyunki max.top has answer when odd len and max.top + min.top when even
		if (maxHeap.size() - minHeap.size() == 2) {
			minHeap.push(maxHeap.top()); // Top element transfer kr do
			maxHeap.pop();
		}

		else if (minHeap.size() - maxHeap.size() == 1) {
			maxHeap.push(minHeap.top());
			minHeap.pop();
		}
	}

	// Function to return the median
	double getMedian() {
		if (maxHeap.size() - minHeap.size() == 1)    // odd length
			return maxHeap.top();
		else										 // even length
			return (maxHeap.top() + minHeap.top()) / 2;
	}
}