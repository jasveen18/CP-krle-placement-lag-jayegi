/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define max4(a, b, c, d) max(a, max3(b, c, d))
#define min4(a, b, c, d) min(a, min3(b, c, d))

#define TestCase ll t = 1; cin >> t; while (t--)
#define vin ll n; cin >> n; vector<int> v(n); for (ll i = 0; i < n; i++) cin >> v[i]
#define vout for (ll i = 0; i < n; i++) cout << v[i] << " "
#define ain ll n, k; cin >> n >> k; ll a[n]; for (ll z = 0; z < n; z++) cin >> a[z]
#define aout for (ll i = 0; i < n; i++) cout << a[i] << " "

#define blink                \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const double PI = 3.141592653589793238463;
/********************************/
/**** Your code goes here - ****/
/*******************************/

void nextPermutation(string &s) {
	int n = s.size();
	int i = n - 2;

	while (i >= 0 and s[i] >= s[i + 1])
		i--;

	if (i == -1)
		return;

	int j = n - 1;
	while (j >= 0 and s[j] <= s[i])
		j--;

	swap(s[i], s[j]);
	reverse(s.begin() + i + 1, s.end());
	return;
}


string findSubString(string A) {
	unordered_map<char, int> count;
	unordered_map<char, int> present;

	for (auto el : A) {
		present[el] = 1;
	}
	int total = present.size();

	int i = 0, j = 0;
	int n = A.size();
	int res = INT_MAX;
	int start = 0;

	while (j < n) {
		if (present[A[j]] and count[A[j]] == 0)
			total--;
		count[A[j]]++;

		if (total == 0) {
			while (total == 0) {
				if (res > j - i + 1) {
					res = j - i + 1;
					start = i;
				}

				count[A[i]]--;
				if (count[A[i]] == 0 and present[A[i]])
					total++;
				i++;
			}
		}

		j++;
	}

	return A.substr(i, res);
}


int knight(int A, int B, int C, int D, int E, int F) {
	// BFS krte hai
	int n = A, m = B; // Dimension of board
	int xs = C - 1, ys = D - 1; // Start position
	int xt = E - 1, yt = F - 1; // Target position

	// BFS ke lie DS
	vector<vector<bool>> vis(n, vector<bool>(m, false));
	queue<pair<int, pair<int, int>>> q;
	q.push({0, {xs, ys}});

	// Movements
	vector<int> delx {2, 2, 1, 1, -1, -1, -2, -2};
	vector<int> dely { -1, 1, -2, 2, -2, 2, -1, 1};

	while (q.empty() == false) {
		int distance = q.front().first;
		int xcurr = q.front().second.first;
		int ycurr = q.front().second.second;
		q.pop();

		// cout<<xcurr<<" "<<ycurr<<"|";

		// Check for target
		if (xcurr == xt and ycurr == yt)
			return distance;

		vis[xcurr][ycurr] = true;

		// BFS for all the directions
		for (int i = 0; i < 8; i++) {
			int x = xcurr + delx[i];
			int y = ycurr + dely[i];

			if (x >= 0 and y >= 0 and x < n and y < m and vis[x][y] == false) {
				q.push({distance + 1, {x, y}});
			}
		}
	}

	return -1;
}




int main() {
	blink
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cout << pickFromBothSides({5, -2, 3, 1, 2}, 3) << endl;
	// cout << pickFromBothSides({1, 2}, 1) << endl;

	return 0;
}