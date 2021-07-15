/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// 1.1886. Determine Whether Matrix Can Be Obtained By Rotation
void rotateMatrix(vector<vector<int>> &mat) {
	// First take transpose
	for (int i = 0; i < mat.size(); i++) {
		for (int j = 0; j < mat.size(); j++) {
			if (i < j) {
				swap(mat[i][j], mat[j][i]);
			}
		}
	}

	// Rotate the rows
	for (int i = 0; i < mat.size(); i++)
		reverse(mat[i].begin(), mat[i].end());

	return;
}


bool isSame(vector<vector<int>>& mat, vector<vector<int>>& target) {
	int n = mat.size();
	int m = target.size();

	if (n != m)
		return false;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (mat[i][j] != target[i][j])
				return false;
		}
	}

	return true;
}

bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
	bool ans = isSame(mat, target);

	if (ans)
		return ans;

	for (int i = 0; i < 3; i++) {
		rotateMatrix(mat);
		if (isSame(mat, target))
			return true;
	}

	return false;
}


// 2. 1887. Reduction Operations to Make the Array Elements Equal
int reductionOperations(vector<int>& nums) {
	int addition = 0;
	int ans = 0;
	int n = nums.size();

	sort(nums.begin(), nums.end());

	for (int i = 1; i < n; i++) {
		if (nums[i] != nums[i - 1]) {
			addition++;
		}

		ans += addition;
	}

	return ans;
}


// 3. 1888. Minimum Number of Flips to Make the Binary String Alternating
int minFlips(string s) {
	int n = s.size();

	// Cyclic Rotation hai toh end pe same string add kro
	// Will slide a window of size 'n'.
	s = s + s;

	// Now find the min number of operations
	int zeroAtEven = 0;
	int oneAtEven = 0;
	int ans = INT_MAX;

	int i = 0, j = 0;
	while (j < s.size()) {
		// Do the calculations
		// Zero at even place
		if ((j & 1) and s[j] != '1')
			zeroAtEven++;
		if (!(j & 1) and s[j] != '0')
			zeroAtEven++;

		// One at even place
		if ((j & 1) and s[j] != '0')
			oneAtEven++;
		if (!(j & 1) and s[j] != '1')
			oneAtEven++;

		if (j - i + 1 < n) { // Window hit ni hua hai
			j++;
		} else if (j - i + 1 == n) { // Window hit ho gya hai
			ans = min(ans, zeroAtEven);
			ans = min(ans, oneAtEven);

			// Now slide the window
			// Zero at even place
			if ((i & 1) and s[i] != '1')
				zeroAtEven--;
			if (!(i & 1) and s[i] != '0')
				zeroAtEven--;

			// One at even place
			if ((i & 1) and s[i] != '0')
				oneAtEven--;
			if (!(i & 1) and s[i] != '1')
				oneAtEven--;


			// Increment i and j
			i++; j++;
		}
	}

	return ans;
}


// 4. 1889. Minimum Space Wasted From Packaging
int minWastedSpace(vector<int> &packages, vector<vector<int>> &boxes) {
	sort(packages.begin(), packages.end());
	long long res = LONG_MAX;
	long long sumA = 0;
	int mod = 1e9 + 7;

	for (auto el : packages)
		sumA += el;

	for (auto &b : boxes) {
		sort(b.begin(), b.end());

		if (b[b.size() - 1] < packages[packages.size() - 1]) continue; // If iss supplier ke saath saare package fit ni honge

		long long curr = 0, i = 0, j;
		for (int boxes : b) {
			j = upper_bound(packages.begin(), packages.end(), boxes) - packages.begin();
			curr += boxes * (j - i);
			i = j;
		}

		res = min(res, curr);
	}

	return res < LONG_MAX ? (res - sumA) % mod : -1;
}