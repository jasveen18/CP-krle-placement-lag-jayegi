/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Find the median of two sorted arrays.

// This is a Hard LC problem because of expected time complexity.
// You don't merge directly and just give median.

// Expected Time Complexity - O(min(LogN, LogM))
// Expected Space Complexity - O(1)

// Solution -
// When you merge the 2 arrays, you can divide them into 2 parts.
// Then to fill the first part -
// Try to pick certain number of elements from arr1, and the left over from arr2.

// Now to check if you made a good partition,
// you need to check if     arr1(1) denotes the first part of arr1.
// 1. the last element of arr1(1) < the first element of arr2(2).
// 2. the last element of arr2(1) < the first element of arr1(2).

// Example -
// arr1 - 1 3 4 5 10 12
// arr2 - 2 3 6 15
// merged -  1 2 3 3 4 6 7 10 12 15

// merged with partition - 1 2 3 3 4 || 6 7 10 12 15

// Our variations -
// 1. 1 3 4 7 || 10 12		Incorrect partition
//          2 || 3 6 15

// 2. 1 3 4 || 7 10 12		Correct partition
//      2 3 || 6 15

// For even number of elements,
// the answer would be max(arr1[l1], arr2[l2]) + min(arr1[r1], arr2[r2]) >> 1;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
	// We are considering nums1 to be larger.
	if (nums1.size() < nums2.size())
		return findMedianSortedArrays(nums2, nums1);

	int n1 = nums1.size();
	int n2 = nums2.size();

	int low = 0, high = n1;

	while (low <= high) {
		int cut1 = (low + high) / 2;
		int cut2 = (n1 + n2 + 1) / 2 - cut1; 	// Left over jitna chaiye in the first part of sorted array.

		int left1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1]; // if zero element bachta hai toh -inf lelo ni toh cut ke pehle wala
		int left2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 2];

		int right1 = cut1 == n1 ? INT_MAX : nums1[cut1]; // if ek bhi element ni bacha to use at the 2nd part.
		int right2 = cut2 == n2 ? INT_MAX : nums2[cut2];

		// Now check if we did the correct partition or not
		if (left1 <= right2 and left2 <= right1) { // Shii partition
			// Check for even length or odd length
			if (n1 + n2 % 2 == 0)
				return (max(left1, left2) + min(right1, righ2)) / 2.0;
			else
				return max(left1, left2);
		} else if (left1 > right2) {	// If shii partition ni hai toh phir BS jaise aage badho.
			high = cut1 - 1;
		} else {
			low = cut1 + 1;
		}
	}

	return 0.0;
}



