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


// Assume the inverse exists - it exists when gcd(a, m) = 1;
// Modulo multiplicative inverse - (a * b) % mod = 1;
int inverseModule(int a, int m) {
	extendedEuclidMethod(a, m);
	return (x + m) % m;
}