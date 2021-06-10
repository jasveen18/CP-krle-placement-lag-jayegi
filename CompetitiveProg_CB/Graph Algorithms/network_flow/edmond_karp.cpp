#include <bits/stdc++.h>
using namespace std;

bool bfs(int **residual_capacity, int source, int sink, int n, int *parent) {
	bool visited[n];
	memset(visited, 0, sizeof(visited));

	queue<int> q;
	visited[source] = true;
	q.push(source);
	bool found_augmented_path = false;

	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (int v = 0; v < n; v++) {
			if (visited[v] == false and residual_capacity[u][v] > 0) {
				parent[v] = u;
				visited[v] = true;
				q.push(v);

				if (v == sink) {
					found_augmented_path = true;
					break;
				}
			}
		}
	}

	return found_augmented_path;
}


void print_augmented_paths(vector<vector<int>> augmented_paths) {
	for (int i = 0; i < augmented_paths.size(); i++) {
		for (int j = 0; j < augmented_paths.size(); j++) {
			cout << augmented_paths[i][j] << ", ";
		}
		cout << endl;
	}
}


int max_flow(int **capacity, int source, int sink, int v) {
	int **residual_capacity = new int*[v];
	for (int i = 0; i < v; i++) {
		residual_capacity[i] = new int[V];
	}

	for (int i = 0; i < v; i++) {
		for (int j = 0; j < v; j++) {
			residual_capacity[i][j] = capacity[i][j];
		}
	}

	int *parent = new int[1000];
	vector<vector<int>> augmented_paths;
	int max_flow = 0;

	while (bfs(residual_capacity, source, sink, v, parent)) {
		vector<int> current_augmented_path;
		int flow = INT_MAX;
		int v = sink;

		while (v != source) {
			current_augmented_path.push_back(v);
			int u = parent[v];
			if (flow > residual_capacity[u][v]) {
				flow = residual_capacity[u][v];
			}

			v = u;
		}

		current_augmented_path.push_back(source);
		reverse(current_augmented_path.begin(), current_augmented_path.end());
		augmented_paths.push_back(current_augmented_path);

		max_flow += flow;

		v = sink;
		while (v != source) {
			int u = parent[v];
			residual_capacity[u][v] -= flow;
			residual_capacity[v][u] += flow;
		}
	}

	return max_flow;
}


int main() {
	int v, e;
	cin >> v >> e;

	int **capacity = new int*[v];

	for (int i = 0; i < v; i++) {
		capacity[i] = new int[v];
	}

	for (int i = 0; i < e; i++) {
		int u, v, wt;
		cin >> u >> v >> wt;

		capacity[u][v] = wt;
	}


}