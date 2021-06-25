/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Function to return the level order traversal of a tree.

// Print the whole traversal in a single line.
vector<int> levelOrder(Node* node) {
    if (node == NULL)
        return {};

    queue<Node*> q;
    vector<int> res;

    q.push(node);

    while (!q.empty()) {
        Node* curr = q.front(); q.pop();

        // Perform the desired operation
        res.push_back(curr->data);

        // Push the child nodes.
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }

    return res;
}


// Print the traversal in multiple lines as per their level