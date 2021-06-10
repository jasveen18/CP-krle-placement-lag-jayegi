// Euclid method to find the gcd.
// O(Lg N)
void gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

// http://www.exlanalytics.in/eq/frontend/web/casedata/EQ_2021_Data_Dictionary.xlsx
// http://www.exlanalytics.in/eq/frontend/web/casedata/EQ_2021_Data_Sample.csv


// Extended Euclid Method
// Ax + By = GCD(A, B). What to put in place of x and y to satisfy the equation.

// Applications -
// 1. Multiplicative Modulo Inverse
// 2. Linear Diophantine Equation


int x, y, GCD;
void extendedEuclidMethod(int a, int b) {
	// Base Case
	if (b == 0) {
		x = 1;
		y = 0;
		GCD = a;
		return;
	}

	// Recursive Case
	extendedEuclidMethod(b, a % b);
	int currX = y;
	int currY = x - (a / b) * y;

	x = currX;
	y = currY;
}