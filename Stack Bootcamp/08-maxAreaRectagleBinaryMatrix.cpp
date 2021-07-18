// *** Max Area Rectangle in Binary Matrix *** //

// Problem Statement ->
// Given a binary matrix find the max area rectangle.

// Reminder ->
// MAH (array) -> max area histogram output deta hai.

// Difference of MAB from MAH
// Binary dia hai and 2D array hai, bss.

// Kya hm 2D array to 1D array bana dun?
// Compress krke MAH hi nikal dete hai.

// Input ->
// 0 1 1 0
// 1 1 1 1
// 1 1 1 1
// 1 1 0 0

// Compresses array
// 0 1 1 0
// 1 2 2 1
// 2 3 3 2
// 3 4 0 0   // Notice in last 2 elements, zero kr die coz ab hawa pe ho jaega na isliye 0.

// Ab har ek row ke lie MAH nikal denge and sbka max() le lenge.

int maxAreaBinaryMatrix(vector<vector<int>> &matrix) {
	int n = matrix.size();
	int m = matrix[0].size();

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (matrix[i][j] == 1)
				matrix[i][j] += matrix[i - 1][j];
		}
	}

	int res = 0;
	for (int i = 0; i < n; i++)
		res = max(res, mah(matrix[i])); // mah function last question se le lena

	return res;
}



