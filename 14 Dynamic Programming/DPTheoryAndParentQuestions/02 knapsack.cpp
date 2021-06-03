// *** Knapsack Problem ***//

// 1. Subset Sum
// 2. Equal Sum Partition
// 3. Count of Subset Sum
// 4. Minimum Subset Sum Difference
// 5. Target Sum
// 6. # of subset sum with given difference

// Knapsack is a bag.

// Problem m kuch items die hue hai: item1, item2, item3, item4.
// Iske saath weights die hue hai, and price die hue hai.

// Hmlog ko items pick krni ki so that profit max ho jaaye.
// But the catch is we can't pick more than x kg, toh kaunse samnaan lu?

// 1. Fractional Knapsack - We are allowed to pick items in fraction. Use Greedy here.
// 2. 0 - 1 Knapsack - We are not allowed to break item, ya toh lo ya ni lo.
// 3. Unbounded Knapsack - We have unlimited supply of items, ek hi item se bhar lo bag baar baar.


/******************************************/
/************** 0-1 Knapsack **************/
/******************************************/

// Identification -
// 1. Choice - hnn choice hai, we can pick or not.
// 2. Optimal - hnn optimal hai, max profit nikalna hai.

// So, we can conclude that DP ki problem hai.


// Ab likho recursive solution.

// How to get base condition?
// Bad Approach - Running recursion for some cases
// Good Approach - Think of the smallest valid input
int knapsackRecursive(int wt[], int val[], int maxWeight, int n) {
	// Base Case
	if (n == 0 or w == 0) {
		return 0;
	}

	// Recursive Cases
	if (wt[n - 1] <= maxWeight) {
		// Exclude Krke
		int excludeKrkeValue = knapsackRecursive(wt, val, maxWeight, n - 1);

		// Include Krke
		int includeKrkeValue = val[n - 1] + knapsackRecursive(wt, val, maxWeight - wt[n - 1], n - 1);
		return max(excludeKrkeValue, includeKrkeValue);
	} else {	// Knapsack pe toh store hi ni kr paa re hai
		return knapsackRecursive(wt, val, maxWeight, n - 1);
	}
}


// Ab memoization kro tum (Top Down)
// Matrix banani hai unhi variables ke lie jo change hora hai.

// DP Matrix
int static t[102][1002];

// Inside main function -
// memset(t, -1, sizeof(t));

int knapsackMemoization(int wt, int val[], int maxWeight, int n) {
	// Base Case
	if (n == 0 or w == 0) {
		return 0;
	}

	// Check DP table
	if (t[n][maxWeight] != -1)
		return t[n][maxWeight];

	// Recursive Cases
	if (wt[n - 1] <= maxWeight) {
		// Exclude Krke
		int excludeKrkeValue = knapsackRecursive(wt, val, maxWeight, n - 1);

		// Include Krke
		int includeKrkeValue = val[n - 1] + knapsackRecursive(wt, val, maxWeight - wt[n - 1], n - 1);
		return t[n][maxWeight] = max(excludeKrkeValue, includeKrkeValue);
	} else {	// Knapsack pe toh store hi ni kr paa re hai
		return t[n][maxWeight] =  knapsackRecursive(wt, val, maxWeight, n - 1);
	}
}


// Ab likhenge Bottom Up Approach (matrix bana kr likhenge)

// Why is it better?
// Recursive Stack ni banega, stack overflow ni hoga, extra recursive stack space ni hoga.

// Disadvantage kya hai phir?
// Mushkil hai likhna isko directly, you will have to derive the recursive code.

// Jo variables change hora hai, ussi variables ki table banayenge.
// Jo table hai usko kaise bharte hai?
// 		1. Initialization
// 		2. Recursive calls ko Iterative version m change kr do.

// Index mapping ek aage se hoga, coz first index of table will be used for initialization.

// Base Condition -> Initialization
// Therefore, j 0->n pe 0 fill kr do in first row.
// 			  i 0->w pe 0 fill kr do in first col.


int knapsackTabulation(int wt[], int val[], int maxWeight, int n) {
	// Initialization
	vector<vector<int>> dp(n + 1, vector<int> (maxWeight + 1, -1));

	// Base condition
	for (int i = 0; i <= n; i++)
		dp[i][0] = 0;
	for (int j = 0; j <= maxWeight; j++)
		dp[0][j] = 0;


	// Build up the DP
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= maxWeight; j++) {
			if (wt[i - 1] <= j) {
				dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]],
				               dp[i - 1][j]);
			} else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	return dp[n][maxWeight];
}