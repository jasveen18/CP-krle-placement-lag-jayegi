/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement -
// You are given a m liter jug and a n liter jug. Both the jugs are initially empty. The jugs don’t have markings to allow measuring smaller quantities. You have to use the jugs to measure d liters of water where d is less than n.

// (X, Y) corresponds to a state where X refers to amount of water in Jug1 and Y refers to amount of water in Jug2
// Determine the path from initial state (xi, yi) to final state (xf, yf), where (xi, yi) is (0, 0) which indicates both Jugs are initially empty and (xf, yf) indicates a state which could be (0, d) or (d, 0).

// The operations you can perform are:

// Empty a Jug, (X, Y)->(0, Y) Empty Jug 1
// Fill a Jug, (0, 0)->(X, 0) Fill Jug 1
// Pour water from one jug to the other until one of the jugs is either empty or full, (X, Y) -> (X - d, Y + d)


// This is also a puzzle.
// We can design a BFS solution by -
// 1. Running each possible state as vertices by doing allowed operations.
// 2. Making edge between achieveable states by a node.
// 3. Running BFS.

typedef pair<int, int> pi;

void BFSTwoJugProblem(int a, int b, int target) {
	map<pi, int> visited;
	bool isSolveable = false;
	vector<tuple<int, int, int>> path;
	map<pi, pi> mp;

	queue<pi> q;
	q.push({0, 0});

	while (!q.empty()) {
		auto u = q.front();
		q.pop();

		// Already visited state
		if (visited[u] == 1)
			continue;

		// Out of bound state
		if ((u.first > a or u.second > b or u.first < 0 or u.second < 0))
			continue;

		// Mark as visited
		visited[ {u.first, u.second}] = 1;

		// Check if target achieved, no logic here, bss printing shii krre hai
		if (u.first == target or u.second == target) {
			printPath(mp, u);
			if (u.first == target) {
				if (u.second != 0)
					cout << u.first << " " << 0 << endl;
			} else {
				if (u.first != 0)
					cout << 0 << " " << u.second << endl;
			}
		}

		// Completely fill Jug2
		if (visited{u.first, b} != 1) {
			q.push(u.first, b);
			mp[ {u.first, b}] = 1;
		}

		// Complete fill Jug1
		if (visited{a, u.second} != 1) {
			q.push(a, u.second);
			mp[ {a, u.second}] = 1;
		}

		// Transfer Jug 1 to Jug 2
		int d = b - u.second;
		if (u.first >= d) {
			int c = u.first - d;
			if (visited{c, b} != 1) {
				q.push(c, b);
				mp[ {c, b}] = 1;
			}
		} else {
			int c = u.first + u.second;
			if (visited{0, c} != 1) {
				q.push(0, c);
				mp[ {0, c}] = 1;
			}
		}

		// Transfer Jug 2 to Jug 1
		int d = a - u.second;
		if (u.second >= d) {
			int c = u.second - d;
			if (visited{a, c} != 1) {
				q.push(a, c);
				mp[ {a, c}] = 1;
			}
		} else {
			int c = u.first + u.second;
			if (visited{c, 0} != 1) {
				q.push(c, 0);
				mp[ {c, 0}] = 1;
			}
		}

		// Empty Jug 1 and Jug 2
		if (visited{0, u.second} != 1) {
			q.push(0, u.second);
			mp[ {0, u.second}] = 1;
		}

		if (visited{u.first, 0} != 1) {
			q.push(u.first, 0);
			mp[ {u.first, 0}] = 1;
		}

	}

	if (!isSolveable)
		cout << "No solution";
}


void printpath(map<pi, pi>mp , pi u) {
	if (u.first == 0 && u.second == 0) {
		cout << 0 << " " << 0 << endl;
		return ;
	}

	printpath(mp, mp[u]);
	cout << u.first << " " << u.second << endl;
}