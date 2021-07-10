/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Convert to Gray Code

// Your solution
int convertToInt(string binary) {
	if (binary.size() == 1)
		return binary[0] - '0';

	int ans = 0;
	for (int i = 0; i < binary.size(); i++) {
		ans *= 2;
		ans += binary[i] - '0';
	}

	return ans;
}


void findTheGray(int n, vector<string> &res) {
	// Base Case -
	if (n == 2) {
		res.push_back("00");
		res.push_back("01");
		res.push_back("11");
		res.push_back("10");
		return;
	}

	// Recursive Case -
	findTheGray(n - 1, res);
	vector<string> temp;

	for (int i = 0; i < res.size(); i++) {
		temp.push_back('0' + res[i]);
	}
	for (int i = res.size() - 1; i >= 0; i--) {
		temp.push_back('1' + res[i]);
	}

	res = temp;
	return;
}

vector<int> Solution::grayCode(int A) {
	if (A == 0) {
		return {0};
	}

	if (A == 1) {
		return {0, 1};
	}

	if (A == 2) {
		return {0, 1, 3, 2};
	}

	// Run recursion from n = 3.
	vector<string> res;
	vector<int> ans;

	findTheGray(A, res);

	for (int i = 0; i < res.size(); i++) {
		ans.push_back(convertToInt(res[i]));
	}

	return ans;
}


// Editorials -
// 1.
vector<int> Solution::grayCode(int A) {
	vector <int> K;
	for (int i = 0; i < (1 << A); i++)
	{
		K.push_back((i ^ (i >> 1)));
	}
	return K;
}

// 2.
vector<int> Solution::grayCode(int A) {
	vector<int> result(1, 0);

	for (int i = 0; i < A; i++) {

		int curSize = result.size();
		// push back all element in result in reverse order
		for (int j = curSize - 1; j >= 0; j--) {
			result.push_back(result[j] + (1 << i));
		}
	}

	return result;
}
