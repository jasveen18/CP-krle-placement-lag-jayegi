// T - O(N * |S| * Log N)
// S - O(N * |S|)
vector<vector<string> > Anagrams(vector<string>& string_list) {
    unordered_map<string, int> groups;
    int n = string_list.size();
    int key = 1;
    for (int i = 0; i < n; i++) {
        string temp = string_list[i]; sort(temp.begin(), temp.end());
        if (groups.find(temp) == groups.end()) {
            groups[temp] = key;
            key++;
        }
    }

    vector<vector<string>> anagramsGrp(groups.size());
    for (int i = 0; i < n; i++) {
        string temp = string_list[i]; sort(temp.begin(), temp.end());
        int idxOfThis = groups[temp] - 1;
        anagramsGrp[idxOfThis].push_back(string_list[i]);
    }

    return anagramsGrp;
}