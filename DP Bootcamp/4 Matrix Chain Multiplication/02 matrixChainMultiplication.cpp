// *** Matrix Chain Multiplication *** //

// 1. Problem Statement
// Question ye hai ki
// Mujhe kuch matrix die hue hai. Mujhe unn matrices ko multiply krni hai.
// Multiply krne m cost lagti hai, we have to minimize that cost.
// Cost ka kya mtlb hai? Number of multiplications.

// Now sbko multiply krni hi hai. Toh same cost kaise ni?
// Kyunki unka dimensions change hoga. Smjhe? A(m*n) * B(n*o) => C(m*o) ki banegi.
// Iss way m multiply krni hai ki ye dimensions shii se optimise ho, so that kam cost lage.

// Cost ->
// Matrix A(2*3)
// Matrix B(3*6)
// C = A*B (2 * 6)
// Cost = 2 * 3 * 6

// Jo dimensions die hue hai, wo ek array m dia hua hai.
// Basically parenthesisation krni hai.
// A*B*C*D ko maan lo A * (B * C) * D ye kie
// 					  (A * B) * (C * D) 2nd example aise bhi kr skte hai.

// Input -
// Jitna size of array hai, size-1 matrices hai.
// Dimensions uss array m dia rakha hai.
// [A0, A1, A2, A3, A4]
// M1 = A0 * A1
// M2 = A1 * A2
//...
// M4 = A3 * A4

// Identification -
// Apan ko pta ni hai ki brackets kaha lagaye ? Isliye har jagah pe try krenge.
// Phir har jagah ke brackets ka temp answer lekr, main answer bana lenge.

// Valid value of i and j identify krlo
// i = 1, j = n-1. 1 kyun? Kyunki matrix ka dimensions will be a[i-1], a[i].
// Toh if i = 0, then i = -1 access krne lagega.

// Base Case -
// i == j rakh le?
// Lekin this means that ek size ka array hai, but matrix hai toh do dimension chaiye.
// Isliye size one ka bhi array is invalid.
// Therefore, base case will be -
// if(i >= j)
// 	return 0;


int mcmMinCostRecursive(int arr[], int i, int j) {
	// Base Case
	if (i >= j)
		return 0;

	// Recursive Case
	int minCost = INT_MAX;
	for (int k = i; k < j; k++) {
		int firstPart = mcmMinCostRecursive(arr, i, k);
		int secondPart = mcmMinCostRecursive(arr, k + 1, j);

		int costHere = arr[i - 1] * arr[k] * arr[j];
		int totalInThisCase = firstPart + secondPart + costHere;

		minCost = min(minCost, totalInThisCase);
	}

	return minCost;
}


int static dp[1001][1001];
// memset(dp, -1, sizeof(dp)); Ye main function pe.
int mcmMinCostTopDown(int arr[], int i, int j) {
	// Base Case
	if (i >= j)
		return 0;

	// Look up the dp table
	if (dp[i][j] != -1)
		return dp[i][j];

	// Recursive Case
	int minCost = INT_MAX;
	for (int k = i; k < j; k++) {
		int firstPart = mcmMinCostTopDown(arr, i, k);
		int secondPart = mcmMinCostTopDown(arr, k + 1, j);

		int costHere = arr[i - 1] * arr[k] * arr[j];
		int totalInThisCase = firstPart + secondPart + costHere;

		minCost = min(minCost, totalInThisCase);
	}

	return dp[i][j] = minCost;
}