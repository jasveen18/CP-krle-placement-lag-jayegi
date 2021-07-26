/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Water Flow
void dfs(vector<vector<int>> &A, vector<vector<int>> &status, int i, int j, int parent, bool blue) {
	if (A[i][j] < parent)
		return;

	if (status[i][j] >= 1 and blue)
		return;

	if (status[i][j] >= 2)
		return;

	if (blue) {
		if (status[i][j] == 0)
			status[i][j]++;
	}
	else {
		if (status[i][j] == 1)
			status[i][j]++;
		else
			status[i][j] = 10;
	}

	vector<int> delx {0, 0, -1, 1};
	vector<int> dely {1, -1, 0, 0};

	for (int k = 0; k < 4; k++) {
		int x = i + delx[k];
		int y = j + dely[k];

		if (x < 0 or y < 0 or x >= A.size() or y >= A[0].size()) continue;
		else dfs(A, status, x, y, A[i][j], blue);
	}
}

int Solution::solve(vector<vector<int> > &A) {
	int n = A.size();
	int m = A[0].size();
	vector<vector<int>> status(n, vector<int>(m, 0)); // 0 -> not visited, 1-> blue water pahuch gya, 2-> red bhi pahuch gya

	// Pehle blue paani pahucha dete hai
	for (int i = 0; i < n; i++) {
		if (status[i][0] == 0)
			dfs(A, status, i, 0, -1, true);
	}
	for (int j = 0; j < m; j++) {
		if (status[0][j] == 0)
			dfs(A, status, 0, j, -1, true);
	}

	// Ab red ko bhara jaaye
	for (int i = 0; i < n; i++) {
		if (status[i][m - 1] == 0 or status[i][m - 1] == 1)
			dfs(A, status, i, m - 1, -1, false);
	}
	for (int j = 0; j < m; j++) {
		if (status[n - 1][j] == 0 or status[n - 1][j] == 1)
			dfs(A, status, n - 1, j, -1, false);
	}


	// Count the nodes
	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (status[i][j] == 2)
				res++;
		}
	}

	return res;
}