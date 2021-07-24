/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node, unordered_map<Node*, Node*> &copies) {
        if (node == NULL)
            return NULL;

        // If not present means ki iska clone ni bana hai
        if (copies.find(node) == copies.end()) {
            copies[node] = new Node(node->val);

            // Add neighbors by DFS
            for (auto nbr : node->neighbors) {
                copies[node]->neighbors.push_back(cloneGraph(nbr, copies));
            }
        }

        return copies[node];
    }

    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> copies;
        return cloneGraph(node, copies);
    }
};




// BFS Solution ->
Node* cloneGraph(Node* node) {
    // BFS solution
    if (node == NULL)
        return NULL;

    unordered_map<Node*, Node*> clone;
    Node* first = new Node(node->val);
    clone[node] = first;

    queue<Node*> todo;
    todo.push(node);

    while (todo.empty() == false) {
        Node* curr = todo.front(); todo.pop();

        // Make it's neighbors
        for (auto nbr : curr->neighbors) {
            if (clone.find(nbr) == clone.end()) { // If ye node ni bana ab tk
                clone[nbr] = new Node(nbr->val);
                todo.push(nbr); // Also insert to process
            }

            clone[curr]->neighbors.push_back(clone[nbr]); // isme naya wala node jayega
        }
    }

    return first;
}