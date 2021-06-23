/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Given a line and points, find the point on the line which will have least distace to each of the given points.

// The distance would be like U. It will decrease and then increase.
// It is not monotonically increase / decreasing, therefore, we will use a ternary search.
// Ternary search skips 1/3rd search space at a time.

// We will take 2 mids and then see where our optimization takes us.

// Define a point
struct point {
	int x, y;
	// Constructors
	point() {}
	point(int x, int y) : x(x), y(y) {}
};


// Define a line
struct line {
	int a, b, c;
	line(int a, int b, int c): a(a), b(b), c(c) {}
};


// Method to get the distance of 2 points
double distanceFunc(double x, double y, point p) {
	return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
}


// Method to compute the total distance from all the points
double computeSumDist(point p[], int n, line l, double x) {
	double res = 0;

	// Calculate the corresponding y wrt x.
	double y = -1 * (l.c + l.a * x) / l.b;

	for (int i = 0; i < n; i++)
		res += distanceFunc(x, y, p[i]);

	return res;
}


// Method to find the minimum distance
double findMinDist(point p[], int n, line l) {
	double low = -1e6;
	double high = 1e6;

	// Since floating numbers pe BS hai toh difference lenge.
	while (high - low > 1e-6) {
		// Calculate mids
		double mid1 = low + (high - low) / 3;
		double mid2 = high - (high - low) / 3;

		// Calculate the total distance using these two mids
		double dist1 = computeSumDist(p, n, l, mid1);
		double dist2 = computeSumDist(p, n, l, mid2);

		// If mid2 gives more distance, then we are sure that there are no answers after mid2
		if (dist1 < dist2)
			high = mid2;

		// If mid1 gives more distance, then wo skip kr denge
		else
			low = mid1;
	}

	// Return distance by taking the average of low and high (even though they are very close now).
	return computeSumDist(p, n, l, (low + high) / 2);
}