// T - O(N)
// S - O(1)
int romanToDecimal(string &str) {
    // Map the characters to their corresponding values.
    unordered_map<char, int> romanNumerals;
    romanNumerals['I'] = 1;
    romanNumerals['V'] = 5;
    romanNumerals['X'] = 10;
    romanNumerals['L'] = 50;
    romanNumerals['C'] = 100;
    romanNumerals['D'] = 500;
    romanNumerals['M'] = 1000;

    int res = 0;
    int i = 0;
    for (i = 0; i < str.size() - 1; i++) {
        // Check for IV, IX, CM, these types of numbers
        if (romanNumerals[str[i]] >= romanNumerals[str[i + 1]]) {
            res += romanNumerals[str[i]];
        } else {
            res += romanNumerals[str[i + 1]] - romanNumerals[str[i]];
            i++;
        }
    }

    // Process the last digits
    if (i == str.size() - 1) {
        if (romanNumerals[str[i]] >= romanNumerals[str[i + 1]])
            res += romanNumerals[str[i]] + romanNumerals[str[i + 1]];
        else
            res += romanNumerals[str[i + 1]] - romanNumerals[str[i]];
    }

    return res;
}