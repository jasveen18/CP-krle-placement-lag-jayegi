/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Return the left view of the tree

vector<int> leftViewTree(Node *root) {
    if (root == NULL)
        return {};

    queue<Node*> q;
    vector<vector<int>> res;
    vector<int> temp;

    q.push(root);

    while (!q.empty()) {
        int sizeHere = q.size();
        for (int i = 0; i < sizeHere; i++) {
            Node* curr = q.front(); q.pop();

            // Perform the desired operation
            temp.push_back(curr->data);

            // Push the child nodes.
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }

        // Push this whole level to the res vector now
        res.push_back(temp);
        temp.clear();
    }

    vector<int> ans;

    for (int i = 0; i < res.size(); i++) {
        ans.push_back(res[i][0]);
    }

    return ans;
}