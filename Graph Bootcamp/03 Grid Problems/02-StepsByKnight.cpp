/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Min Steps to reach one position to another position by a knight.
// N is the board dimension. (N*N)
// BFS shortest path deta hai.
int minStepsKnight(vector<int> &startPos, vector<int> &finalPos, int N) {
	int res = INT_MAX;
	vector<vector<bool>> visited(n + 1, vector<bool>(n + 1, false));

	// Make the queue and insert the first starting position
	queue < pair<int, pair<int, int>>> q;
	q.push({0, {startPos[0], startPos[1]}});
	visited[startPos[0]][startPos[1]] = true;

	// Movements
	int dx[] = { -1, 1, -1, 1, -2, -2, 2, 2};
	int dy[] = {2, 2, -2, -2, -1, 1, -1, 1};

	// BFS Traversal
	while (!q.empty()) {
		int currSteps = q.front().first;
		pair<int, int> currCor = q.front().second;
		q.pop();

		// If this is the target position
		if (currCor.first == finalPos[0] and currCor.second == finalPos[1])
			return currSteps;

		// Traverse the valid positions
		for (int k = 0; k < 8; k++) {
			// Check for valid
			int x = currCor.first + dx[k];
			int y = currCor.second + dy[k];
			if (x > 0 and y > 0 and x <= N and y <= N and visited[x][y] == false) {
				q.push({currSteps + 1, {x, y}});
			}
		}
	}

	return res;
}