// T - O(N)
// S - O(N)
bool areIsomorphic(string str1, string str2) {
    unordered_map<char, char> mapString;
    set<char> seenChars;
    int n = str1.size();
    int m = str2.size();

    // Invalid Case
    if (n != m)
        return false;

    for (int i = 0; i < n; i++) {
        if (mapString.find(str1[i]) == mapString.end()) {
            mapString[str1[i]] = str2[i];
            if (seenChars.find(str2[i]) == seenChars.end())
                seenChars.insert(str2[i]);
            else
                return false;
        }
        else if (mapString[str1[i]] != str2[i])
            return false;
    }

    return true;
}


// T - O(N)
// S - O(N)
bool areIsomorphic(string str1, string str2) {
    int n = str1.size();
    int m = str2.size();

    int countOne[256] = {0};
    int countTwo[256] = {0};

    // Invalid Case
    if (n != m)
        return false;

    for (int i = 0; i < n; i++) {
        countOne[str1[i]]++;
        countTwo[str2[i]]++;

        // If it is not equal at this point, return false
        if (countOne[str1[i]] != countTwo[str2[i]])
            return false;
    }

    return true;
}