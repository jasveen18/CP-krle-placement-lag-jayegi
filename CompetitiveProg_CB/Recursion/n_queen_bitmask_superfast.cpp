int n;
int ans = 0;
int DONE = (1 << n) - 1;

void nQueen(int rowMask = 0, int ld = 0, int rd = 0) {
	if (rowMask == DONE) {ans++; return;}

	int safe = DONE & (~(rowMask | ld | rd));
	while (safe) {
		int p = safe & (-safe);
		safe = safe - p;

		nQueen(rowMask | p, (ld | p) << 1, (rd | p) >> 1);
	}
}