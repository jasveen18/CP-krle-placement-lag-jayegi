vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) {
	int startRow = 0;
	int startCol = 0;
	int endRow = r - 1;
	int endCol = c - 1;

	vector<int> res(r * c, 0);
	int i = 0;

	// Stop conditions
	while (startRow <= endRow and startCol <= endCol) {
		// First Row
		for (int i = startCol; i <= endCol; i++) {
			arr[i++] = matrix[startRow][i];
		}
		startRow++;

		// End Column
		for (int i = startRow; i <= endRow; i++) {
			arr[i++] = matrix[i][endCol];
		}
		endCol--;

		// Bottom Row
		if (endRow >= startRow) {
			for (int i = endCol; i >= startCol; i--) {
				arr[i++] = matrix[endRow][i];
			}
			endRow--;
		}

		// First Column
		if (endCol >= startCol) {
			for (int i = endRow; i >= startRow; i--) {
				arr[i++] = matrix[i][startCol];
			}
			startCol++;
		}
	}

	return arr;
}