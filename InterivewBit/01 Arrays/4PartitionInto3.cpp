/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Count the number of ways to divide the array into 3 parts such that sbka sum same ho.
int Solution::solve(int A, vector<int> &B) {
	int n = A;

	// Take sum
	int sumAll = 0;
	for (int i = 0; i < n; i++)
		sumAll += B[i];
	int sumEach = sumAll / 3;

	// Check for not possible case
	if (sumAll % 3 != 0 or B.size() < 3)
		return 0;

	int oneThirdCount = 0;
	int oneThirdSum = sumEach;
	int twoThirdSum = 2 * sumEach;

	// Number of ways
	int count = 0;

	int currSum = 0;
	for (int i = 0; i < n - 1; i++) {
		currSum += B[i];

		if (currSum == twoThirdSum)	// When we encounter a 2/3rd case then that means ki 1/3rd iske baad hoga hi toh ab tk ka ways add krdo
			count += oneThirdCount;
		if (currSum == oneThirdSum) // Potential cases, they will be added when 2/3rd mil jayega iska
			oneThirdCount++;
	}

	return count;
}
