// ** Optimization in DSU ** //

// 1. Path Compression (findSet) -> Instead of traversing to reach the top parent, directly store the top parent only.
// 2. Union by Rank (unionSet) -> We union the set as merging the smaller set to larger set.

// After doing these 2 operations, we have almost O(1) time complexity for DSU

// Only modifying the required function

int findSet(int i, int parent[]) {
	if (parent[i] == -1)
		return i;

	// Path compression here
	// Just like DP top parent ko store kr lere hai har jagah instead of immediate parent
	return parent[i] = findSet(parent[i], parent);
}


// Here we have a new space (rank array) to store the rank (length) of each set
bool unionSet(int x, int y, int parent[], int rank[]) {
	int s1 = findSet(x);
	int s2 = findSet(y);

	if (s1 == s2)
		return true;

	if (rank[s1] < rank[s2]) { // Since s2 is larger, wo s1 ko consume krega
		parent[s1] = s2;
		rank[s2] += rank[s1]; // Update rank of s2
	} else {
		parent[s2] = s1;
		rank[s1] += rank[s2];
	}

	return false;
}