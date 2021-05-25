// T - O(N * max length of string)
// S - O(N)
string longestCommonPrefix(vector<string>& strs) {
    // Take the prefix array
    string commonPrefix = "";

    // Add all elements for the first array
    commonPrefix = strs[0];
    cout << commonPrefix << endl;

    // Iterate over all the elements and match common
    for (int i = 1; i < strs.size(); i++) {
        // Trim commonPrefix if it is larger than current element.
        commonPrefix = commonPrefix.substr(0, strs[i].size());

        for (int j = 0; j < strs[i].size(); j++) {
            // Valid case
            if (j < commonPrefix.size() and commonPrefix[j] == strs[i][j]) {
                continue;
            }

            // Break case
            if (j >= commonPrefix.size())
                break;

            // Trim if following element is not equal
            if (commonPrefix[j] != strs[i][j]) {
                commonPrefix = commonPrefix.substr(0, j);
                break;
            }
        }
    }

    return commonPrefix;
}