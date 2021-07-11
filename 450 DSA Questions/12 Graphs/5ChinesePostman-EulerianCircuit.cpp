/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - find the shortest path or circuit that visits every edge of the graph atleast once.
// It is a Eulerian circuit (visit every node once and go back to start).

// An undirected and connected graph has Eulerian cycle if “all vertices have even degree“.
// If eulerian is present, then that is the shortest path.

// Algorithm to find shortest closed path or optimal
// Chinese postman route in a weighted graph that may
// not be Eulerian.
// step 1 : If graph is Eulerian, return sum of all
//          edge weights.Else do following steps.
// step 2 : We find all the vertices with odd degree
// step 3 : List all possible pairings of odd vertices
//          For n odd vertices total number of pairings
//          possible are, (n-1) * (n-3) * (n -5)... * 1
// step 4 : For each set of pairings, find the shortest
//          path connecting them.
// step 5 : Find the pairing with minimum shortest path
//          connecting pairs.
// step 6 : Modify the graph by adding all the edges that
//          have been found in step 5.
// step 7 : Weight of Chinese Postman Tour is sum of all
//          edges in the modified graph.
// step 8 : Print Euler Circuit of the modified graph.
//          This Euler Circuit is Chinese Postman Tour.


//                3
//         (a)-----------------(b)
//      1 /  |                  |  \1
//       /   |                  |   \
//      (c)  | 5               6|   (d)
//       \   |                  |   /
//      2 \  |         4        |  /1
//         (e)------------------(f)
// As we see above graph does not contain Eulerian circuit
// because is has odd degree vertices [a, b, e, f]
// they all are odd degree vertices .

// First we make all possible pairs of odd degree vertices
// [ae, bf], [ab, ef], [af, eb]
// so pairs with min sum of weight are [ae, bf] :
// ae = (ac + ce = 3 ),  bf = ( bd + df = 2 )
// Total : 5

// We add edges ac, ce, bd and df to the original graph and
// create a modified graph.