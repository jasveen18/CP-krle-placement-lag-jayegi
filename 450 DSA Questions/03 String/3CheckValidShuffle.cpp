// Check if one string is valid shuffle of two other strings.
// 1XY2 is a valid shuffle of XY and 12
// Y12X is not a valid shuffle of XY and 12
// T - O(N)
// S - O(1)
bool validShuffle(string res, string a, string b) {
	int resLen = res.length();
	int n = a.length();
	int m = b.length();

	// If length doesn't match
	if (m + n != resLen)
		return false;

	int i = 0, j = 0, k = 0;
	while (i < n or j < n) {
		// If matches with a
		if (i < n and res[k] == a[i])
			i++;
		// If matches with b
		else if (j < m and res[k] == b[j])
			j++;
		// Doesn't match with valid shuffle
		else
			return false;

		k++;
	}

	// Count didn't go till length
	if (i < n or j < m)
		return false;

	// All conditions satisfy
	return true;

}