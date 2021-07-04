/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Max Overlapping interval
bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    vector<pair<int, char>> cords;
    int n = arrive.size();

    for (int i = 0; i < n; i++) {
        // If arrival then add as "x".
        cords.push_back({arrive[i], 'x'});
        // If depart then add as "y".
        cords.push_back({depart[i], 'y'});
    }

    // Sort by time so that interval map kr skte
    sort(cords.begin(), cords.end(), [](pair<int, char> &a, pair<int, char> &b) {
        // if same time, then pehle bahar nikalo
        if (a.first == b.first)
            return a.second > b.second;

        return a.first < b.first;
    });

    // Idea is to when x is there, then ek new guest aaya toh count++.
    // and when y aaya mtlb someone left, then count--.
    // There should be no more than K guests at a time.
    int countGuests = 0;
    int maxGuests = 0;

    for (int i = 0; i < cords.size(); i++) {
        if (cords[i].second == 'x')
            countGuests++;

        if (cords[i].second == 'y')
            countGuests--;

        maxGuests = max(maxGuests, countGuests);
    }

    if (maxGuests > K)
        return false;

    return true;
}
