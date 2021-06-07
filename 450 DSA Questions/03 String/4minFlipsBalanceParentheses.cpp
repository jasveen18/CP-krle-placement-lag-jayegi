int countRev(string s) {
    int n = s.size();

    // Check for odd length
    if (n & 1)
        return -1;

    int flips = 0;
    int opening = 0, closing = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '{')
            opening++;
        else
            closing++;

        // Whenever this happens we need to handle it
        if (opening < closing) {
            flips++;
            closing--;
            opening++;
        }
    }

    // Flips + Number of openings left, so we will have to flip half of them
    return flips + ((opening - closing) / 2);
}