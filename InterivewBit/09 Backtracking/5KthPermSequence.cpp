/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Kth Permutation Sequence
string Solution::getPermutation(int A, int B) {
    if (A == 1)
        return "1";

    int pos = 0;
    int n = A;
    string res = "";
    vector<int> numbers;
    vector<int> factorial(n + 1, 0);

    // Create a factorial lookup table
    factorial[0] = 1;
    int prod = 1;
    for (int i = 1; i <= n and i <= 11; i++) {
        prod *= i;
        factorial[i] = prod;
    }

    for (int i = 12; i <= n; i++)
        factorial[i] = INT_MAX;

    // Create the list of number
    for (int i = 0; i < n; i++)
        numbers.push_back(i + 1);

    // Things starting from zero
    B--;

    for (int i = 1; i <= n; i++) {
        int index =  B / factorial[n - i]; // Get the respective index of the element jisko hona chaiye
        res += to_string(numbers[index]);
        numbers.erase(numbers.begin() + index);

        B -= index * factorial[n - i];
    }

    return res;
}
