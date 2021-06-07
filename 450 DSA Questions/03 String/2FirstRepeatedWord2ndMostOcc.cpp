// T - O(N)
// S - O(N)
string secFrequent (string arr[], int n) {
    unordered_map<string, int> countEl;
    for (int i = 0; i < n; i++) {
        countEl[arr[i]]++;
    }

    vector<pair<string, int>> sortThis;
    for (auto el : countEl)
        sortThis.push_back(el);

    sort(sortThis.begin(), sortThis.end(), [](pair<string, int> &a, pair<string, int> &b) {
        return a.second < b.second;
    });

    return sortThis[sortThis.size() - 2].first;
}