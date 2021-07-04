// ** M Coloring Problem ** //

// Is it possible to color the graph with max of M colors such that
// no two adjacent nodes have same color.

// We will use Recursion to try every possible combinations.
bool graphColoring(int graph[101][101], int m, int n) {
	int color[n] = {0};
	if (canPutColor(0, color, m, n, graph))
		return true;

	return false;
}


bool canPutColor(int src, int color[], int m_color, int n, int graph[101][101]) {
	// Base Case -
	if (src == n)
		return true;

	// Recursive Case -
	// We will try to put every possible color onto each node
	for (int i = 1; i <= m_color; i++) {
		if (isSafeToColor(src, color, graph, n, i)) {
			color[src] = i;

			bool smallerSubprob = canPutColor(src + 1, color, m_color, n, graph);
			if (smallerSubprob)
				return true;
		}
	}

	// Backtrack
	color[src] = 0;
	return false;
}


bool isSafeToColor(int src, int color[], int graph[101][101], int n, int currColor) {
	// k is every node.
	for (int k = 0; k < n; k++) {
		// If 'k' parent hi ni hai, k ke saath node hai and k is not colored jo color iske lie pick kie hai.
		if (k != src and graph[k][src] == 1 and color[k] == currColor)
			return false;
	}

	return true;
}