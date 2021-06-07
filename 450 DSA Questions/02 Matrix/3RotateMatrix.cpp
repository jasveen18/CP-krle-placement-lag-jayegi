// Approach 1 - Reverse each row and then take transpose
// Time Complexity - O(N*N)
// Space Complexity - O(1)
void rotateMatrix(vector<vector<int>> &matrix, int n) {
	// Reverse each row
	for (int i = 0; i < n; i++) {
		reverse(matrix[i].begin, matrix[i].end());
	}

	// Do Transpose
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i < j) {
				swap(matrix[i][j], matrix[j][i]);
			}
		}
	}

	return;
}