/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Function to find majority element in the array
// a: input array
// size: size of input array

// Booyer Mayer Voting Algorithm
int majorityElement(int a[], int size) {
    int majorityNow = a[0];
    int countMajor = 1;

    // Pick the candidate for majority element
    for (int i = 1; i < size; i++) {
        if (majorityNow == a[i])
            countMajor++;
        else
            countMajor--;

        if (countMajor == 0) {
            majorityNow = a[i];
            countMajor = 1;
        }
    }

    // Verify if it is the majority element or not
    int countActual = 0;
    for (int i = 0; i < size; i++) {
        if (a[i] == majorityNow)
            countActual++;
    }

    return countActual > (size / 2) ? majorityNow : -1;
}