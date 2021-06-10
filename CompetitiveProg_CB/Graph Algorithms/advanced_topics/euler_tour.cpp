// Time In and Time Out ke saath kaam krre hai.
// To find the ancestors and least common insector.

const int N = 100005, M = 22;
vector<int> gr[N];
int tin[N], tout[N], timer = 0;


bool is_ancestor(int x, int y) {
	return tin[x] <= tin[y] and tout[x] >= tout[y];
}


void euler_tour_first_approach(int cur, int par) {
	cout << cur << " ";
	tin[cur] = timer++;
	for (auto x : gr[cur]) {
		if (x != par) {
			euler_tour_first_approach(x, cur);
		}
	}
	tout[cur] = timer++;
	cout << cur << " ";
}


void euler_tour_second_approach(int cur, int par) {
	cout << cur << " ";
	tin[cur] = timer++;
	for (auto x : gr[cur]) {
		if (x != par) {
			euler_tour_first_approach(x, cur);
			cout << cur << " ";
			tout[cur] = timer++;
		}
	}
}


void euler_tour_third_approach(int cur, int par) {
	cout << cur << " ";
	tin[cur] = ++timer;
	for (auto x : gr[cur]) {
		if (x != par) {
			euler_tour_first_approach(x, cur);
		}
	}
	tout[cur] = timer;
}


int euler_tour() {
	int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;

		gr[x].push_back(y);
		gr[y].push_back(x);
	}

	// timer = 1;
	// euler_tour_first_approach(1, 0);
	// euler_tour_second_approach(1, 0);

	// For third appraoch, timer will initialize at 1.
	// timer = 1;
	// euler_tour_third_approach(1, 0);
	return 0;
}