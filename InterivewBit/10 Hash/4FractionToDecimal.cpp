/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Convert fraction to decimal
string Solution::fractionToDecimal(int numerator, int denominator) {
    if (!numerator) {
        return "0";
    }
    string ans;

    // Sign
    if (numerator > 0 ^ denominator > 0) {
        ans += '-';
    }

    // Check if directly divisible
    long n = labs(numerator), d = labs(denominator), r = n % d;
    ans += to_string(n / d);
    if (!r) {
        return ans;
    }

    // No? Then add decimal
    ans += '.';
    unordered_map<long, int> rs;

    while (r) {

        // Recurring aa gya
        if (rs.find(r) != rs.end()) {
            ans.insert(rs[r], "(");
            ans += ')';
            break;
        }

        rs[r] = ans.size();
        r *= 10;
        ans += to_string(r / d);
        r %= d;
    }
    return ans;
}
