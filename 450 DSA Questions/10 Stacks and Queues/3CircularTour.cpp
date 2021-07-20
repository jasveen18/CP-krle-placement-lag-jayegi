/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement -
//Function to find starting point where the truck can start to get through
//the complete circle without exhausting its petrol in between.
int tour(petrolPump p[], int n) {
    int idx = 0;
    int local = 0;

    for (int i = 0; i < 2 * n - 1; i++) {
        local += p[i % n].petrol - p[i % n].distance;
        if (local < 0) {
            idx = i + 1;
            local = 0;
            continue;
        }

        if (i - idx + 1 == n)
            return idx;
    }

    return -1;
}