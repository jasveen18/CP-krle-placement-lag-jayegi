string countAndSay(int n) {
    // Base Case
    if (n == 1)
        return "1";

    // Recursive Case
    string subProb = countAndSay(n - 1);
    int count = 0;
    char num = subProb[0];

    // Result for this call
    string res = "";

    // Count and say
    for (int i = 0; i < subProb.size(); i++) {
        if (num == subProb[i]) {
            count++;
        } else {
            res += to_string(count) + num;
            num = subProb[i];
            count = 1;
        }
    }

    // Add the left over part
    res += (to_string(count) + num);

    return res;
}