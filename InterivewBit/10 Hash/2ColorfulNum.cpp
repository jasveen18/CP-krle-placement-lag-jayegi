/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - If the number is colorful.
https://www.interviewbit.com/problems/colorful-number/
int Solution::colorful(int A) {
    string num = to_string(A);
    unordered_set<long long> isPresent;

    int n = num.size();
    int prod = 1;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            prod *= (num[j] - '0');

            if (isPresent.find(prod) != isPresent.end())
                return 0;
            isPresent.insert(prod);
        }

        prod = 1;
    }

    return 1;
}
