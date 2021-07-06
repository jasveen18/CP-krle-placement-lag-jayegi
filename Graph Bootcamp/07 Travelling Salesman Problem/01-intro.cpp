// ** Travelling Salesman Problem ** //

// Problem - We have some locations and a source, we want to visit all the location and come back in min cost.
// We want to find the min cost route.

// Our goal is to find our min weight Hamiltonian Path.
// It is classified as NP-Hard, there is no "quick" solution, and it grows exponentially.

// Brute Force Approach -
// Calculate and compare all possible permutations of routes or paths to determine the shortest unqiue solution.
// Given n nodes, we will have (n)!.
// We will start from warehouse, then it is (n-1)!.

// 1. Start from A, go to all the not visited neighbors.
// 2. In the base case we will reach all the cities and we will return the cost of reaching the next node.

// if(all_visited) return cost_to_source_from_current_city
// else min_cost = min(current_cost + recuFunc(...))


// DP kaha se aaya?
// A - B - C - [N-3 more nodes left]
// A - C - B - [N-3 more nodes left]
// So the rest of those 3 nodes will give the same min cost.