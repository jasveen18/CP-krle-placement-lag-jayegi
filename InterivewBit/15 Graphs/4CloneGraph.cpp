/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Clone a graph
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

UndirectedGraphNode* cloneThis(UndirectedGraphNode* node, unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> &copies) {
    if (node == NULL)
        return NULL;

    if (copies.find(node) == copies.end()) {
        copies[node] = new UndirectedGraphNode(node->label);

        for (auto nbr : node->neighbors) {
            UndirectedGraphNode* nbrAfterCalc = cloneThis(nbr, copies);
            copies[node]->neighbors.push_back(nbrAfterCalc);
        }
    }

    return copies[node];
}

UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> copies;
    return cloneThis(node, copies); // DFS Solution
}
