// Simple variant of BFS/DFS that can be used to label(color)
// various connected components of a graph.
// It is generally performed on implicit graphs(2D Matrix)
// Starting from particular cell we call 'DFS' on the neighboring cells
// to color them. Neighbors can be '4' (up, down, left right) or '8' (diagonals)


// W, N, E, S
int dx[] = { -1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

void floodFill(char mat[][50], int i, int j, char ch, char color) {
	// Base Case - Matrix Bounds
	if (i<0 or j<0 or i >= R or j >= C) {
		return;
	}

	// Figure Boundary Condition
	if (mat[i][j] != ch) {
		return;
	}

	// Recursive Case
	mat[i][j] = color;
	for (int k = 0; k < 4; k++) {
		floodFill(mat, i + dx[k], j + dy[k], ch, color);
	}

}