/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement -
/* Given N jobs where every job is represented by following three elements of it.

1. Start Time
2. Finish Time
3. Profit or Value Associated
Find the maximum profit subset of jobs such that no two jobs in the subset overlap.
*/

struct Job {
	int start, finish, profit;
}

bool sortingByFinish(Job j1, Job j2) {
	return j1.finish < j2.finish;
}

// ************************************ //
// Approach 1 - Simple Recursion with Include / Exclude Principle. - O(N * 2^N)

// Find the first non-conflicting job after taking 'i'th job
int latestNonConflicting(Job jobs[], int i) {
	for (int j = i - 1; j >= 0; j--) {
		if (jobs[j].finish <= jobs[i - 1].start)
			return j;
	}

	// There are no jobs possible if we take this job.
	return -1;
}


// Find the max profit recusively
int findMaxProfitRecursive(Job jobs[], int n) {
	// Base Case
	if (n == 1)
		return jobs[0].profit;

	// Recursive Cases -
	// 1. Include krenge
	int includeProfit = jobs[n - 1].profit;
	int nextJob = latestNonConflicting(jobs, n);

	if (nextJob != -1)
		includeProfit += findMaxProfitRecursive(jobs, nextJob + 1); // Now find the max in smaller subprob


	// 2. Exclude krenge
	int excludeProfit = findMaxProfitRecursive(jobs, n - 1);

	return max(includeProfit, excludeProfit);
}


// Main function to sort and call the recursive function
int findMaxProfit(Job jobs[], int n) {
	sort(jobs, jobs + n, sortingByFinish);

	return findMaxProfitRecursive(jobs, n);
}

// ************************************ //
// Approach 2 - Dynamic Programming - O(N*N)
// We can use DP to optimize the overlapping subproblems.

// Find the first non-conflicting job after taking 'i'th job
int latestNonConflicting(Job jobs[], int i) {
	for (int j = i - 1; j >= 0; j--) {
		if (jobs[j].finish <= jobs[i - 1].start)
			return j;
	}

	// There are no jobs possible if we take this job.
	return -1;
}

// Main function to sort and find the profit using bottom up DP.
int findMaxProfit(Job jobs[], int n) {
	sort(jobs, jobs + n, sortingByFinish);

	// Initialization
	vector<int> dp(n);
	dp[0] = jobs[0].profit;

	// Build up the DP
	for (int i = 1; i < n; i++) {
		// Include case
		int includeProfit = jobs[i].profit;

		int prevJob = latestNonConflicting(jobs, i);
		if (prevJob != -1)
			includeProfit += dp[prevJob];

		// Exclude case
		int excludeProfit = dp[i - 1];

		dp[i] = max(includeProfit, excludeProfit);
	}

	return dp[n - 1];
}


// ************************************ //
// Approach 3 - Dynamic Programming with Binary Search - O(N*Log N)
// We can use DP to optimize the overlapping subproblems and optimize the search of latest conflict using Binary Search.

// Find the first non-conflicting job after taking 'i'th job
int latestNonConflictingBinarySearch(Job jobs[], int i) {
	int start = 0, end = i - 1;

	while (start <= end) {
		int mid = start + (end - start) / 2;

		// If we find the correct index
		if (jobs[mid].finish <= jobs[i].start) {
			if (jobs[mid + 1].finish <= jobs[i].start) // Next job should be higher **
				start = mid + 1;
			else
				return mid;
		} else { // Look piche
			end = mid - 1;
		}
	}

	// No jobs possible
	return -1;
}

// Main function to sort and find the profit using bottom up DP.
int findMaxProfit(Job jobs[], int n) {
	sort(jobs, jobs + n, sortingByFinish);

	// Initialization
	vector<int> dp(n);
	dp[0] = jobs[0].profit;

	// Build up the DP
	for (int i = 1; i < n; i++) {
		// Include case
		int includeProfit = jobs[i].profit;

		int prevJob = latestNonConflictingBinarySearch(jobs, i);
		if (prevJob != -1)
			includeProfit += dp[prevJob];

		// Exclude case
		int excludeProfit = dp[i - 1];

		dp[i] = max(includeProfit, excludeProfit);
	}

	return dp[n - 1];
}