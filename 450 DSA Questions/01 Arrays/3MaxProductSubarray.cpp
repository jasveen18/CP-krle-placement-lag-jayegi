// Approach - Considering all negative we will only omit one neg number.
// 			  So, forward and backward will omit the desired element.
// 			  Kinda like Kadane's algo
// Time Complexity - O(N)
// Space Complexity - O(1)
long long maxProduct(int *arr, int n) {
	long long int forwardPass = arr[0];
	long long int maxF = arr[0];
	long long int backwardPass = arr[n - 1];
	long long int maxB = arr[n - 1];

	// Forward Pass
	for (int i = 1; i < n; i++) {
		// If the element is zero
		if (forwardPass == 0)
			forwardPass = 1;
		forwardPass = forwardPass * arr[i];
		maxF = max(forwardPass, maxF);
	}

	// Backward Pass
	for (int i = n - 2; i >= 0; i--) {
		// If the element is zero
		if (backwardPass == 0)
			backwardPass = 1;
		backwardPass = backwardPass * arr[i];
		maxB = max(backwardPass, maxB);
	}

	long long int minVal = 0;
	return max(minVal, max(maxF, maxB));
}