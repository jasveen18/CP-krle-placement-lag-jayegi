// Approach - Sort the array and then use 2 pointer approach
// Time Complexity - O(N*N)
// Space Complexity - O(1)
bool find3Numbers(int A[], int n, int X) {
	sort(A, A + n);

	for (int i = 0; i < n - 2; i++) {
		int start = i + 1, end = n - 1;
		while (start < end) {
			int sumHere = A[i] + A[start] + A[end];
			if (sumHere == X) {
				return true;
			} else if (sumHere > X) {
				end--;
			} else {
				start++;
			}
		}
	}

	return false;
}