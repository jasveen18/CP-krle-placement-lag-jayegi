/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Fractional Knapsack, maximize profit
//Function to get the maximum total value in the knapsack.
static bool sortBy(Item &a, Item &b) {
	return (((1.0 * a.value) / a.weight)) > (((1.0 * b.value) / b.weight));
}

double fractionalKnapsack(int W, Item arr[], int n) {
	double maxProfit = 0.0;

	// Sort by their value / weight.
	sort(arr, arr + n, sortBy);

	for (int i = 0; i < n; i++) {
		if (arr[i].weight <= W) {
			maxProfit += arr[i].value;
			W -= arr[i].weight;
		} else {
			maxProfit += (((1.0 * arr[i].value) / arr[i].weight)) * W;
			W = 0;
			break;
		}
	}

	return maxProfit;
}