/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Return the min edges to remove to reach destination from source.
// Approach -
// 1. Add reversed edgest with weight = 1.
// 2. Keep the original edges as weight = 0.

// Now, we do Dijsktra algorithm to find the min cost incurred.
// min cost = min edges to remove.

// We can also find which edges we need to reverse.

// Straightforward to implement.
// Bss reverse edges with 1 weight add kr do and Djisktra chala dena.