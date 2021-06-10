bool safe(int board[][10], int i, int j, int n) {
	// Check directly above
	for (int row = 0; row < i; row++) {
		if (board[row][j] == 1)
			return false;
	}

	// Check for Left Diagonal
	int x = i;
	int y = j;
	while (x >= 0 and y >= 0) {
		if (board[x][y])
			return false;

		x--;
		y--;
	}

	// Check for Right Diagonal
	x = i;
	y = j;
	while (x >= 0 and y < n) {
		if (board[x][y])
			return false;

		x--;
		y++;
	}

	return true;
}


bool nQueenSolver(int board[][10], int i, int n) {
	// Base Case
	if (i == n) {
		// This means that we have solved the board.
		// Therefore, we will print the board.
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] == 1)
					cout << "Q";
				else
					cout << "_";
			}
			cout << endl;
		}
		cout << endl;

		///// return true; /////

		// Here we are return false, to print all the possible solutions.
		// What this false will do, that tell the person that the soln found
		// if false, even when the soln is true. We printed it. Now we move on
		// to the next tile to find the solution.
		return false;
	}

	// Recursive Case
	for (int j = 0; j < n; j++) {
		if (safe(board, i, j, n)) {
			// Place the queen, assuming i, j is right position
			board[i][j] = 1;

			bool nextQueenRakhPaaye = nQueenSolver(board, i + 1, n);
			if (nextQueenRakhPaaye)
				return true;

			// Backtracking - if the current position doesn't yield soln
			// i, j is not the right position - Galat assumption.
			board[i][j] = 0;
		}
	}

	// We have tried for all the columns in current row
	// but was not able to find a solution.
	return false;
}