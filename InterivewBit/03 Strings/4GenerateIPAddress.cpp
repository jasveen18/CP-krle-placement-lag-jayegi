/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Generate all IP Addresses
vector Solution::restoreIpAddresses(string A) {


    vector<string> res;
    if (A.length() > 12 || A.length() < 4) return res;

    // Take the length of first num as 1 to 3, and try all combinations. Aise hi for each place
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            for (int k = 1; k <= 3; k++) {
                for (int l = 1; l <= 3; l++) {
                    if (i + j + k + l > A.length() || i + j + k + l < A.length()) continue;
                    string a = A.substr(0, i);
                    string b = A.substr(i, j);
                    string c = A.substr(i + j, k);
                    string d = A.substr(i + j + k, l);
                    if ( stoi(a) > 255 || stoi(b) > 255 || stoi(c) > 255 || stoi(d) > 255 ) continue;
                    if ( (a[0] == '0' && a.length() > 1) ||
                            (b[0] == '0' && b.length() > 1) ||
                            (c[0] == '0' && c.length() > 1) ||
                            (d[0] == '0' && d.length() > 1)) continue;
                    res.push_back(a + "." + b + "." + c + "." + d);
                }
            }
        }
    }
    return res;

}