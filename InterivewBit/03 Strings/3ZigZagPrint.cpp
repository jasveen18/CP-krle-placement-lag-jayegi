/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Print in zig zag
string Solution::convert(string a, int b) {
    int rowNum = 0;
    bool down = true;

    if (b == 1)
        return a;

    vector<string> rows(b);
    for (int i = 0; i < b; i++)
        rows[i] = "";

    int n = a.size();

    for (int i = 0; i < n; i++) {
        rows[rowNum] += a[i];

        if (rowNum == b - 1)
            down = false;

        if (rowNum == 0)
            down = true;

        if (down)
            rowNum++;
        else
            rowNum--;
    }

    string res = "";
    for (int i = 0; i < b; i++) {
        res += rows[i];
        // cout<<rows[i];
    }

    return res;
    // return "";
}
