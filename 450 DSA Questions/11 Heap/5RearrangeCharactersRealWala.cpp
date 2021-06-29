/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Rearrange chars such that no 2 are repeating

// Approach 1 - Using count array.
// Good logic
string reorganizeString(string s) {
    int n = s.size();
    int count[26] = {0};
    int mostFreqChar = 0;
    int mostFreq = 0;

    for (int i = 0; i < n; i++) {
        count[s[i] - 'a']++;
        if (mostFreq < count[s[i] - 'a']) {
            mostFreqChar = s[i] - 'a';
            mostFreq = count[s[i] - 'a'];
        }
    }

    // cout<<mostFreq<<endl;
    if (mostFreq > (n + 1) / 2) return "";

    // Assign the most occuring char at even places
    int i = 0;
    while (count[mostFreqChar]) {
        s[i] = mostFreqChar + 'a';
        i += 2;
        count[mostFreqChar]--;
    }

    for (int j = 0; j < 26; j++) {
        while (count[j]) {
            // 2 case - either mostfreq pura even places fill kr lie or not.
            // Toh agar pura filled, then that means i overflows now.
            // Or ni toh even places pe hi aage bharna start kr do.
            // If 'i' overflows then usko odd places pe le aao.
            if (i >= n) i = 1;
            s[i] = j + 'a';


            count[j]--;
            i += 2;
        }
    }

    return s;
}