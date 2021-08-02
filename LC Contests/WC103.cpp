// 1. Smallest Range I
//     Intuition:
// If min(A) + K < max(A) - K, then return max(A) - min(A) - 2 * K
// If min(A) + K >= max(A) - K, then return 0
int smallestRangeI(vector<int>& A, int K) {
	return max(0, *max_element(begin(A), end(A)) - K - (*min_element(begin(A), end(A)) + K));
}


// 2. Snake and Ladders


// 3. Smallest Range II
