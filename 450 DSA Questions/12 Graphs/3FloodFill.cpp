/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Color the connecting nodes with a new color

// L, U, R, D
int dx[] = { -1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

void floodFill(vector<vector<int>> &mat, int i, int j, int newColor) {
	// Base Case - Matrix bound
	if (i >= mat.size() or j >= mat[0].size() or i < 0 or j < 0)
		return;

	// 0 is empty cell, 1 is old color
	if (mat[i][j] == 0)
		return;

	mat[i][j] = newColor;
	for (int k = 0; k < 4; k++)
		floodFill(mat, i + dx[k], j + dy[k], newColor);
}