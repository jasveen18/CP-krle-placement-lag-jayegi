/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Function to find the maximum number of meetings that can
//be performed in a meeting room.
static bool sortByEnd(pair<int, int> &a, pair<int, int> &b) {
    return a.second < b.second;
}

int maxMeetings(int start[], int end[], int n) {
    vector<pair<int, int>> meetings(n);

    for (int i = 0; i < n; i++) {
        meetings[i].first = start[i];
        meetings[i].second = end[i];
    }

    sort(meetings.begin(), meetings.end(), sortByEnd);

    int ans = 0;
    int endMeet = -1;

    for (int i = 0; i < n; i++) {
        if (meetings[i].first > endMeet) {
            ans++;
            endMeet = meetings[i].second;
        }
    }

    return ans;
}