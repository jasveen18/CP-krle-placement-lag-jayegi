/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// 1. 961. N-Repeated Element in Size 2N Array
int repeatedNTimes(vector<int>& A) {
	for (int i = 0; i < A.size() - 2; ++i)
		if (A[i] == A[i + 1] || A[i] == A[i + 2]) return A[i];
	return A[A.size() - 1];
}

// 2.