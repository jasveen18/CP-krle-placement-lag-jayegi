/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
vector<Interval> Solution::merge(vector<Interval> &A) {
    // Sort by starting time to start merging from start
    sort(A.begin(), A.end(), [](Interval & a, Interval & b) {
        if (a.start == b.start)
            return a.end < b.end;

        return a.start < b.start;
    });

    vector<Interval> res;

    // Take the first values to initiate the merging
    int endTime = A[0].end;
    int startTime = A[0].start;

    for (int i = 1; i < A.size(); i++) {
        // This means ki non-overlap hai
        if (A[i].start > endTime) {
            res.push_back(Interval(startTime, endTime));

            // Update the new start and end time.
            startTime = A[i].start;
            endTime = A[i].end;
        }
        // Overlap hai, take the one which is ending later
        else {
            endTime = max(endTime, A[i].end);
        }
    }

    res.push_back(Interval(startTime, endTime));
    return res;
}
