bool canPlace(int sudoku[][9], int i, int j, int n, int num) {
	// Check for rows and columns
	for (int x = 0; x < n; x++) {
		if (sudoku[i][x] == num || sudoku[x][j] == num)
			return false;
	}

	// Check for the subgrid
	int rn = sqrt(n);
	int start_grid_x = (i / rn) * rn;
	int start_grid_y = (j / rn) * rn;

	for (int x = start_grid_x; x < start_grid_x + rn; x++) {
		for (int y = start_grid_y; y < start_grid_y + rn; y++) {
			if (sudoku[x][y] == num)
				return false;
		}
	}

	return true;
}

bool sudokuSolver(int sudoku[][9], int i, int j, int n = 9) {
	// Base Case
	if (i == n) {
		// We have traversed all the rows and columns
		// Print the sudoku
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << sudoku[i][j];
			}
			cout << endl;
		}

		return true;
	}

	// Conditions.
	// If we reached the end of current row
	if (j == n)
		return sudokuSolver(sudoku, i + 1, 0, n);

	// Skip the pre-filled cells
	if (sudoku[i][j] != 0)
		return sudokuSolver(sudoku, i, j + 1, n);


	// Recursive Case
	for (int num = 1; num <= n; num++) {
		if (canPlace(sudoku, i, j, n, num)) {
			// Assume that the placed number is correct
			sudoku[i][j] = num;

			// Can we solve smaller problem with current number?
			bool canSolveNext = sudokuSolver(sudoku, i, j + 1, n);
			if (canSolveNext)
				return true;
		}
	}

	// Backtracking step - we were not able to place any of the numbers yet.
	sudoku[i][j] = 0;
	return false;
}