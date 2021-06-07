/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
* https://www.geeksforgeeks.org/program-generate-possible-valid-ip-addresses-given-string/ *
******************************************/

// Brute Force Approach -
// Nested Loops
// T - O(N^4) ?
// S - O(N)
bool isValidIp(string ip) {
	// Split by "."
	vector<string> blocks;
	string temp = "";
	for (int i = 0; i < ip.size(); i++) {
		if (ip[i] == '.') {
			blocks.push_back(temp);
			temp = "";
		} else {
			temp += ip[i];
		}
	}

	// Now check each block
	for (int i = 0; i < blocks.size(); i++) {
		if (blocks[i].size() > 3 or
		        stoi(blocks[i]) > 255 or
		        stoi(blocks[i]) < 0)
			return false;

		if (blocks[i].size() > 1 and stoi(blocks[i]) == 0)
			return false;

		if (blocks[i].size() > 1 and blocks[i][0] == '0')
			return 0;
	}

	return true;
}


vector<string> convertStringToIP(string ip) {
	int n = ip.size();

	if (n > 12 or n < 4)
		return {};

	string ipToCheck = ip;
	vector<int> ans;

	// Generate different combinations
	for (int i = 1; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++) {
				ipToCheck = ipToCheck.substr(0, k) + "."
				            + ipToCheck.substr(k, n - k + 2);
				ipToCheck = ipToCheck.substr(0, j) + "."
				            + ipToCheck.substr(j, n - j + 3);
				ipToCheck = ipToCheck.substr(0, i) + "."
				            + ipToCheck.substr(i, n - i + 4);
			}

			if (isValidIp(ipToCheck))
				ans.push_back(ipToCheck);
		}
	}

	return ans;
}


// Logic Based Approach -
// String toh 3 part pe hi divide hoga -
// Gazab O(9) pe chal gya shyd
vector<string> restoreIpAddresses(string s) {
	std::vector<std::string> ret;

	for (int a = 1; a <= 3; ++a) {
		for (int b = 1; b <= 3; ++b) {
			for (int c = 1; c <= 3; ++c) {
				int d = s.size() - a - b - c;
				// Last number must use all remaining digits. Check;
				// 1. The size of the last number is valid
				// 2. Every number uses 1 digit for 0 and is less than 255 if using 3 digits
				if (1 <= d && d <= 3 &&
				        (1 == a || '0' != s[0        ] && (3 != a || 0 < memcmp("256", &s[0        ], 3))) &&
				        (1 == b || '0' != s[a        ] && (3 != b || 0 < memcmp("256", &s[a        ], 3))) &&
				        (1 == c || '0' != s[a + b    ] && (3 != c || 0 < memcmp("256", &s[a + b    ], 3))) &&
				        (1 == d || '0' != s[a + b + c] && (3 != d || 0 < memcmp("256", &s[a + b + c], 3))))
				{
					ret.emplace_back(s.substr(0, a) + "." + s.substr(a, b) + "." + s.substr(a + b, c) + "." + s.substr(a + b + c));
				}
			}
		}
	}

	return ret;
}





