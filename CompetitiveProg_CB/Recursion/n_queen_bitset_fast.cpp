// We will use bitset array to check the if the position is safe
// to fill or not. Earlier we were using O(N) time to check this.
// Now we will do it in O(N) time.

// Columns, diagonal 1, diagonal 2.
bitset<30> col, d1, d2;

void nQueenFast(int i, int n, int &ans, int board[][20]) {
	if (i == n) {
		ans ++;
		return;
	}

	for (int column = 0; column < n; column++) {
		if (!col[column] and !d1[r - column + n - 1] and !d2[i + column]) {
			col[column] = d1[r - column + n - 1] = d2[i + column] = board[i][column] = 1;
			nQueenFast(i + 1, n, ans);

			// Backtrack
			col[column] = d1[r - column + n - 1] = d2[i + column] = board[i][column] = 0;
		}
	}
}


