/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Copy set bits in a given range.

// Approach 1 - Do it one by one
void copySetBits(unsigned &x, unsigned &y, unsigned l, unsigned r) {
	if (l < 1 or r > 32)
		return;


	for (int i = l; i <= r; i++) {
		// Make a mask for that position
		int mask = (1 << (i - 1));

		// If it is set bit, then set x ka bit
		if (y & mask)
			x = x or mask;
	}
}

// Approach 2 - One mask for all
void copySetBits(unsigned &x, unsigned &y, unsigned l, unsigned r) {
	if (l < 1 or r > 32)
		return;


	int maskLen = (1 << (r - l + 1)) - 1;

	// Shift mask to the starting position and then do 'and' with y.
	int mask = ((maskLen) << (l - 1)) & y;
	x = x or mask;
}