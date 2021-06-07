// Given an integer n, calculate the square of a number without using *, / and pow().
int calculateSquare(int n) {
	// n^2 => (2n + 1)^2 or (2n)^2
	if (n == 0)
		return 0;

	if (n < 0)
		n = -n;

	int x = n >> 1;

	if (n & 1) {
		return (calculateSquare(x) << 2) + (x << 2) + 1;
	} else {
		// Left shift operation will multiply by 4
		return (calculateSquare(x) << 2);
	}
}