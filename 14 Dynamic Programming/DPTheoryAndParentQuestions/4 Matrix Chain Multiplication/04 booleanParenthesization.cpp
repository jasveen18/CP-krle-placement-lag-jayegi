// *** Boolean Parenthesization *** //

// or evaluate expression to true.

// 1. Problem Statement -
// Ek string dia hoga with some symbols and true and false -
// T - true
// F - false
// | - or
// & - and
// ^ - xor
// Example - "T^F&T"
// We have to evaluate ki kaise brackets lagaye so that ye true hoga.
// Number of putting brackets nikalna hai ki true evaluate ho.

// Identification ? -
// Ki paritions krni hogi and saare paritions ko check krni hogi.
// partitions dekho toh ek operator ke around hoga, not number
// isliye k = k+2 krna hoga, so that operators pe land ho.
// T ya F pe break ni kr skte na.

// Format m aate hai -
// 1. Find i and j
// 	  i = 0 se start kr denge and j = size-1 toh shii lag ra hai.
// 2. Base case -
// 	  agar ek hi value rhega toh answer will same as the symbol, if empty then return false
// 	  overview hai ye - detailed pe code pe dekhte hai.
// 	  if(i > j)
// 	  	return 0;
// 	  if(i == j)
// 	  	return s[i] == 'T'?
// 3. loop ka expression kaise hoga? -
//    k ko start from i+1 till j-1
//    i to k-1 and k+1 to j and k pe mera operator hoga. k = k+2 krenge
// 4.

// 5. Ek hidden feature hai iss question ka.
// We need to check both true and false for smaller subprobs.
// Kyunki suppose if the operator is xor.
// Then A xor B = true when one of them is false. Isliye we need to track the false cases too.

// Code dekhte hai -
// Sidhe Top Down hi likh re hai, recursive bhi voi hi hai.
// Also 3D matrix banegi, as teen variables change hore hai.
// Isliye usse better map bana lenge, with unique key as - i + " " + j + " " + isTrue.
unordered_map<string, int> dp;
// dp.clear(); in main function kr do. just in case.
int booleanParenthesization(string s, int i, int j, bool isTrue) {
	// Make the key for this function call
	string key = to_string(i) + " " + to_string(j) + " " + to_string(isTrue);

	// Base Case
	if (i > j)
		return dp[key] = 0;
	if (i == j) {
		if (isTrue == true)
			return dp[key] = s[i] == 'T' ? 1 : 0;
		else
			return dp[key] = s[i] == 'F' ? 1 : 0;
	}

	// Look up the dp table
	if (dp.find(key) != dp.end())
		return dp[key];

	// Recursive Case -
	int ans = 0;
	for (int k = i + 1; k < j; k += 2) {
		// Find the number of ways considering all ways.
		int trueInLeft = booleanParenthesization(s, i, k - 1, true);
		int falseInLeft = booleanParenthesization(s, i, k - 1, false);
		int trueInRight = booleanParenthesization(s, k + 1, j, true);
		int falseInRight = booleanParenthesization(s, k + 1, j, false);

		// The operator that we have to evaluate here.
		char operatorAtK = s[k];

		if (operatorAtK == '&') {
			if (isTrue) { // This means we have to find true with AND operator
				// there is only possiblity when both are true
				ans += trueInLeft * trueInRight;
			} else { // We have to find false with AND operator
				ans += falseInLeft * trueInRight;
				ans += trueInLeft * falseInRight;
				ans += falseInLeft * falseInRight;
			}
		}

		if (operatorAtK == '|') {
			if (isTrue) { // This means we want the expression to be true with OR operator
				ans += falseInLeft * trueInRight;
				ans += trueInLeft * falseInRight;
				ans += trueInLeft * trueInRight;
			} else {
				ans += falseInLeft * falseInRight;
			}
		}

		if (operatorAtK == '^') {
			if (isTrue) {
				ans += falseInLeft * trueInRight;
				ans += trueInLeft * falseInRight;
			} else {
				ans += falseInLeft * falseInRight;
				ans += trueInLeft * trueInRight;
			}
		}
	}

	return dp[key] = ans;
}