
// 1. Source - The vertex which produces the material
// 2. Sink - The vertex where we need the material
// 3. Flow - Exact amount of material flowing through edge.
// 4. Pipe - Edges
// 5. Capacity - Maximum amount of material that can flow through edge.
// 6. Residual Capacity - (Capacity - Flow)
// 7. Augmented Path - Path from source to sink, such that residual capacity
// 					on every edge is greater that zero.
// 					For an augmented path, the maximum flow is the minimum
// 					weight.
