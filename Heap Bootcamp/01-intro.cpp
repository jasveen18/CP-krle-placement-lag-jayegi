// *** HEAP *** //

// Mostly problems krenge, kaise implement krte hai wo jaakr sikh lena.
// Stack se represent krenge, k size ka.

// Identification -
// 1. "K" dia hoga.
// 2. Smallest ya largest dia hoga.

// Ek simple solution smjh aayega ki sort kr de.
// Usko hi optimise krenge from O(NLogN) -> O(NLogK)

// How to choose the heap -
// 1. Min -> K + Largest dia hai toh min heap
// 2. Max -> K + Smallest dia hai toh max heap

// Elements daalte jao and jaise hi heap ka size > k, pop kr do.
// End m after traversing, jo top pe hua voi answer hoga.

// Generic Code -
// Max Heap -
// priority_queue<int> maxHeap;

// Min Heap -
// priority_queue<int, vector<int>, greater<int>> minHeap;