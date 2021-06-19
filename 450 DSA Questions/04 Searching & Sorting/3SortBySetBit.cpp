/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Sort by their number of bits.

void sortBySetBitCount(int arr[], int n)
{
    stable_sort(arr, arr + n, [](int a, int b) {
        int countA = 0, countB = 0;
        int tempA = a, tempB = b;
        while (tempA) {
            tempA &= (tempA - 1);
            countA++;
        }

        while (tempB) {
            tempB &= (tempB - 1);
            countB++;
        }

        return countA > countB;
    });
}