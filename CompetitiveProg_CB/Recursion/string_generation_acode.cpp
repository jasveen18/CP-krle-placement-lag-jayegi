void generateStrings(char *n, char *out, int i, int j) {
    // Base Case
    if (n[i] == '\0') {
        out[j] = '\0';
        cout << out << endl;
        return;
    }

    // Recursive Case
    // One digit at a time
    int digit = n[i] - '0';
    if (digit > 0) {
        char ch = digit + 'A' - 1;

        out[j] = ch;
        generateStrings(n, out, i + 1, j + 1);
    }

    // Two digit at a time
    if (n[i + 1] != '\0') {
        int secondDigit = n[i + 1] - '0';
        int number = digit * 10 + secondDigit;

        if (number <= 26) {
            ch = number + 'A' - 1;
            out[j] = ch;
            generateStrings(n, out, i + 2, j + 1);
        }
    }

    return;
}