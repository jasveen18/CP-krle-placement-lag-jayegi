int findLongestConseqSubseq(int arr[], int N) {
  int isPresent[100000 + 4] = {0};
  int maxEl = 0;

  // Mark all the elements present in array
  for (int i = 0; i < N; i++) {
    isPresent[arr[i]]++;
    maxEl = max(maxEl, arr[i]);
  }

  int longestSubSeq = 0;
  int runningSubSeq = 0;

  // Compute longest sub sequence
  for (int i = 0; i <= maxEl; i++) {
    // If sequence is broke
    if (isPresent[i] == 0) {
      runningSubSeq = 0;
    } else {
      runningSubSeq++;
    }

    longestSubSeq = max(longestSubSeq, runningSubSeq);

  }

  longestSubSeq = max(longestSubSeq, runningSubSeq);

  return longestSubSeq;
}