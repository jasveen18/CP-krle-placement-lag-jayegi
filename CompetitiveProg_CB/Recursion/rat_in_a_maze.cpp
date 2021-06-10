#include<bits/stdc++.h>
using namespace std;

bool ratInMaze(char maze[10][10], char soln[10][10], int i, int j, int m, int n) {
	// Base Case
	if (i == m and j == n) {
		soln[m][n] = 1;

		// Print the path.
		for (int i = 0; i <= m; i++) {
			for (int j = 0; j <= n; j++) {
				cout << soln[i][j] << " ";
			}
			cout << endl;
		}
		cout << "---------";
		return true;
	}

	// Pruning - Rat should be inside grid
	if (i > m || j > n)
		return false;

	// Condition
	if (maze[i][j] == 'X')
		return false;

	// Recursive Case
	soln[i][j] = 1;

	bool rightSuccess = ratInMaze(maze, soln, i + 1, j, m, n);
	bool downSuccess = ratInMaze(maze, soln, i, j + 1, m, n);


	// Backtracking - Print krne ke lie 1 kie the. Toh ap wapis 0 krre hai
	// So that next solution can read it and go on the path.
	soln[i][j] = 0;

	if (rightSuccess || downSuccess)
		return true;
	else
		return false;
}


int main() {
	char maze[10][10] = {
		"0000",
		"00X0",
		"000X",
		"0X00",
	};
	int m = 4, n = 4;

	int soln[10][10] = {0};

	bool pathExists = ratInMaze(maze, soln, 0, 0, m - 1, n - 1);
	if (!pathExists)
		cout << "Path doesn't exist." << endl;
}