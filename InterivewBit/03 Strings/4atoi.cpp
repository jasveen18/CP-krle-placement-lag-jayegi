/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Convert string to int
int Solution::atoi(const string s) {
    string num = "";
    int start = 0;
    int n = s.size();
    bool neg = false;

    if (n == 0)
        return 0;


    // Remove whitespaces before the number
    while (start < n and s[start] == ' ')
        start++;

    // Check if number is there at first place
    if (s[start] > '9' or s[start] < '0' and s[start] != '-' and s[start] != '+')
        return 0;

    if (s[start] == '-') {
        neg = true;
        start++;
    }

    if (s[start] == '+') {
        start++;
    }

    int end = start;
    while (end < n and s[end] >= '0' and s[end] <= '9')
        end++;

    for (int i = start; i < end; i++)
        num += s[i];

    if (num.size() > 10) {
        return neg ? INT_MIN : INT_MAX;
    }

    // Convert the string into number
    long long int res = 0;
    for (int i = 0; i < num.size(); i++) {
        res *= 10;
        res += (num[i] - '0');
    }

    if (res >= INT_MAX) {
        return neg ? INT_MIN : INT_MAX;
    } else {
        return neg ? -res : res;
    }
}
