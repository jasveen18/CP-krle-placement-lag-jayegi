// 1.
string largestTimeFromDigits(vector<int>& arr) {
	int resh = 0, resm = 0;
	vector<int> res;
	int count = 24;

	sort(arr.begin(), arr.end());

	for (int i = 0; i < 24; i++)  {

		int h = arr[0] * 10 + arr[1];
		int m = arr[2] * 10 + arr[3];

		// Check validity
		if (h <= 23 and m < 60) {
			// Check if greater than ans
			if (resh * 60 + resm <= h * 60 + m) {
				resh = h;
				resm = m;
				res = arr;
			}
		}


		next_permutation(arr.begin(), arr.end());
	}

	if (res.size() == 0)
		return "";

	string strRes = to_string(res[0]) + to_string(res[1]) + ":" + to_string(res[2]) + to_string(res[3]);
	return strRes;
}