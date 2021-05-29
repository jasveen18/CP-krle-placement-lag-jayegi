bool isSafeForQueen(vector<vector<int>> &board, int i, int j) {
	// Check the column. Row pe toh ni hoga.
	for (int row = 0; row < i; row++) {
		if (board[row][j])
			return false;
	}

	// Check for left diagonal
	int x = i;
	int y = j;
	while (x >= 0 and y >= 0) {
		if (board[x][y])
			return false;

		x--; y--;
	}

	// Check for right diagonal
	x = i;
	y = j;
	while (x >= 0 and y < board.size()) {
		if (board[x][y])
			return false;

		x--; y++;
	}


	return true; // If all conditions don't match.
}



bool printAllNQueens(int n, vector<vector<int>> &board, int i) {
	// Base Case when we have arranged the board
	if (i == n) {

		// Print the board
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] == 1)
					cout << "Q";
				else
					cout << ".";
			}
			cout << endl;
		}
		cout << endl;

		return false; // To find further configurations
	}

	// Recursive Case
	for (int j = 0; j < n; j++) {
		// Place queen at i, j if it is safe.
		if (isSafeForQueen(board, i, j)) {
			board[i][j] = 1;

			// Run further
			bool nextQueensRakhPaaye = printAllNQueens(n, board, i + 1);
			if (nextQueensRakhPaaye)
				return true;

			// If not, backtrack
			board[i][j] = 0;
		}
	}

	// We couldn't place the queen here because of our previous configs
	return false;
}


void driverPrintQueens(int n) {
	vector<vector<int>> board(n, vector<int>(n));

	// Arrange the board and print when final config
	printAllNQueens(n, board, 0);
	return;
}