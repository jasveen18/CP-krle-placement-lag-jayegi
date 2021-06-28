/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Find the minimum possible sum of two numbers formed using the elements of the array.
string findSum(string num1, string num2) {
    int i = num1.size() - 1, j = num2.size() - 1;
    string res = "";
    int carry = 0;

    while (i >= 0 and j >= 0) {
        int dig1 = num1[i] - '0';
        int dig2 = num2[j] - '0';

        int sumHere = (dig1 + dig2 + carry);
        int dig = sumHere % 10;
        carry = sumHere / 10;

        res = to_string(dig) + res;

        i--; j--;
    }

    while (i >= 0) {
        int dig1 = num1[i] - '0';

        int sumHere = (dig1 + carry);
        int dig = sumHere % 10;
        carry = sumHere / 10;

        res = to_string(dig) + res;
        i--;
    }

    while (j >= 0) {
        int dig2 = num1[i] - '0';

        int sumHere = (dig2 + carry);
        int dig = sumHere % 10;
        carry = sumHere / 10;

        res = to_string(dig) + res;
        j--;
    }

    if (carry != 0) {
        res = to_string(carry) + res;
    }

    // Check for any preceding zeroes
    for (int i = 0; i < res.size(); i++) {
        if (res[i] != '0')
            return res.substr(i);
    }

    return "0";
}


string solve(int arr[], int n) {
    sort(arr, arr + n);

    string num1 = "0";
    string num2 = "0";

    for (int i = 0; i < n; i++) {
        if (i & 1)
            num2 += to_string(arr[i]);
        else
            num1 += to_string(arr[i]);
    }

    return findSum(num1, num2);
}