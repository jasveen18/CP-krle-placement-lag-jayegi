// Program to perform power(a, n)
int power(int a, int n) {
	if (n == 1)
		return a;

	if (n & 1)
		return a * power(a, n - 1);

	return power(a, n / 2) * power(a, n / 2);
}


// Program to perform binary search
int binary_search(vector<int> &nums, int low, int high, int target) {

	int mid = low + (high - low) / 2;

	if (nums[mid] == target)
		return mid;
	else if (nums[mid] < target)
		return binary_search(nums, mid + 1, high, target);
	else
		return binary_search(nums, low, mid, target);

	if (low > high)
		return -1;
}