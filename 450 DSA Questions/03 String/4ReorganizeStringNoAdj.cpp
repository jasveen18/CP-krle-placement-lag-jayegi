/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Reorganize string in such a way that no same element are adjacent
string reorganizeString(string s) {
    // start with counting
    int maxEl = 0;
    int maxCount = 0;
    int n = s.size();
    vector<int> count(26, 0);


    for (int i = 0; i < s.size(); i++) {
        count[s[i] - 'a']++;

        if (maxCount < count[s[i] - 'a']) {
            maxCount = count[s[i] - 'a'];
            maxEl = s[i] - 'a';
        }
    }

    // If not possible
    if (maxCount > (n + 1) / 2)
        return "";

    // Place at even places
    int i = 0;
    while (count[maxEl]) {
        s[i] = (maxEl + 'a');

        count[maxEl]--;
        i += 2;
    }

    // Now place every other element
    for (int j = 0; j < 26; j++) {
        while (count[j]) {
            if (i >= n)  // Check if overflow, then odd places pe fill krne lago
                i = 1;

            count[j]--;
            s[i] = (j + 'a');
            i += 2;
        }
    }

    return s;
}