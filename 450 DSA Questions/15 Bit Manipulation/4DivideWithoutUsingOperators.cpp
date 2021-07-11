/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Divide 2 numbers (floor) without using '/', '%' or '*'.

// Approach 1 - Use repeated subtraction
// Subtract krte rho till the divident is smaller than divisor.
// T - O(Dividend) | S - O(1)


// Approach 2 - Use Bit Manipulation

// Dividend - (quotient * divisor) >= 0.
// 43 - x*8 >= 0.

// Now we know that we can represent each number in power of 2.
// We will represent quotient(x) in power of 2.

// We need to find max power of 2 for which the above equation holds.

// 43 - 2^2 * 8 >= 0 is true.
// 43 - 4*8 = 11.

// But, 11 is still greater than 8.
// Therefore, we will try the next smaller power
// 11 - 2 * 8 ---> This is less than zero. So, moving on

// 11 - 1*8 = 3 --> this is correct


// Key -
// Instead of subtracting the divisor again and again, we can do that in power of 2s.

// Now, instead of moving from dividend, let's start from divisor and start adding again and again.
int divideNums(int dividend, int divisor) {
	long long n = dividend, m = divisor;

	int sign = n < 0 ^ m < 0 ? -1 : 1;  // Check sign if both have equal signs then be positive.
	n = abs(n);
	m = abs(m);
	long long q = 0, t = 0;

	// Starting from the most significant bit to find the quotient
	for (int i = 31; i >= 0; i--) {
		// Check if dividend will be larger than q*divisor
		// m << i => 2^i * m. For first iteration -> 2^31 * m
		if (t + (m << i) <= n) {
			t += m << i;   // If smaller hai toh add kr do
			q = q or (1LL << i); // Take that bit as 1, wo answer hoga
		}
	}

	if (sign < 0) q = -q; // Check for sign
	return q >= INT_MAX or q <= INT_MIN ? INT_MAX : q;
}