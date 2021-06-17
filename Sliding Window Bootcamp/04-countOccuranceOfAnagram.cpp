// *** Count Occurance of Anagram *** //

// Problem Statement -
// Given two strings, 2nd string ki saari anagrams ko find krni hai in 1st string.
// Uska count dena hai.

// Problem Identification -
// 1. String di hui hai, ek pattern dia hua hai.
// 2. Substring nikalna hai, anagram form krra hai ya ni.
// 3. Window size bhi dekho dia hai, that is length of 2nd string(pattern).

// M unique char count isliye banaya so that mujhe map ko baar baar check na krna pade.
// Constant time ho jaega isse. Please read again kyunki this is a very good optimisation.
int countOccurenceAnagrams(string text, string pattern) {
	int size = text.size();
	int k = pattern.size();
	int countOccurances = 0;
	int countCharPresent = 0;
	unordered_map<int, int> charCount;

	for (int i = 0; i < k; i++)
		charCount[pattern[i]]++;
	// Update the size of map.
	countCharPresent = charCount.size();

	int i = 0, j = 0;
	while (j < size) {
		// Operation for new element
		if (charCount.find(text[j]) != charCount.end()) {
			charCount[text[j]]--;

			// Agar zero ho jaara hai toh unique char count ko decrement kr do
			if (charCount[text[j]] == 0)
				countCharPresent--;
		}

		// If window size ni bani ab tk
		if (j - i + 1 < k) {
			j++;
		} else if (j - i + 1 == k) {
			// Ab check krlo ki number of elements match krra hai ya ni
			// Agar count pe kuch hai hi ni toh mtlb match krra hai
			if (countCharPresent == 0)
				countOccurances++;

			// Ab slide krenge
			// Ye ekdum reverse hogi
			if (charCount.find(text[i]) != charCount.end()) {
				if (charCount[text[i]] == 0)  // char count badha do if ye zero tha kyunki ab increase hoga
					countCharPresent++;

				charCount[text[i]]++;
			}
			i++; j++;
		}
	}

	return countOccurances;
}