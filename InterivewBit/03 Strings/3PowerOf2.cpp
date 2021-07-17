/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Check power of 2. |S| <= 100
int Solution::power(string A) {
	int n = A.size();

	if (A == "2")
		return 1;

	if ((A[n - 1] - '0') % 2 == 1)
		return 0;

	int carry = 0;
	bool insert = true;
	string res = "";

	// Divide by 2
	for (int i = 0; i < n; i++) {
		int num = A[i] - '0';
		num += carry * 10;
		carry = num % 2;
		num = num / 2;

		if (insert == false or num != 0) {
			res += (num + '0');
			insert = false;
		}
	}

	return power(res);
}
