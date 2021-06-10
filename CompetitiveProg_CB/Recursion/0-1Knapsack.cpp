int profit(int N, int C, int wt[], int price[]) {
	/*
	N: number of items
	C: weight the theif can carry
	wt: weight of item i
	price: price of item i

	returns the max profit
	*/

	// Base Case
	if (N == 0 || C == 0)
		return 0;

	// Recursive Case
	int include, exclude;
	include = exclude = 0;

	// When we including the last item. Condition: we can only include
	// if we have cost left > weight of that item
	if (C >= wt[n - 1])
		include = price[n - 1] + profit(N - 1, C - wt[n - 1], wt, price);

	// When we are excluding the last item
	exclude = profit(N - 1, C, wt, price);

	return max(include, exclude);
}