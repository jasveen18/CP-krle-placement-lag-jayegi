// 1. Flow <= Max capacity of an edge
// 2. The amount of flow going inside at every vertex should be
//    equal to flow going outside (excluding source and sink)
// 3. For an augmented path, the max flow is the min weight.
// 4. In augmented path, there should not be non-zero backward edge and
//    a non full forward edge.

// Algorithm:
// 1. Setup our directed residual graph with edge capacity = original graph weight.
// 2. max_flow = 0
// 3. while(there exist any augmented path from source to sink) {
// 	find 'f', the min edge weight along the current path.

// 	decrease the capacity of all the forward edges by f
//     increase the capacity of all the backward edges by f
//     max_flow += f
//    }
// 4. print max_flow

// We will use DFS to find all the augmented paths.
// If we use BFS to find all the augmented path, then it is Edmond Karp Algorithm
