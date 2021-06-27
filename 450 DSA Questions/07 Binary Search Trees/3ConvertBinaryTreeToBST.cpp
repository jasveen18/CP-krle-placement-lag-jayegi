/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement -  The given root is the root of the Binary Tree
// Return the root of the generated BST
void preOrderTree(Node* root, vector<int> &res) {
    // Base Case -
    if (root == NULL)
        return;

    res.push_back(root->data);
    preOrder(root->left, res);
    preOrder(root->right, res);
}

Node* inOrderBST(Node* root, vector<int> data, int &index) {
    if (root == NULL or index == data.size())
        return NULL;

    root->left = inOrder(root->left, data, index);
    // Operations -
    root->data = data[index++];

    root->right = inOrder(root->right, data, index);
    return root;
}

Node *binaryTreeToBST (Node *root) {
    vector<int> data;
    preOrderTree(root, data);

    sort(data.begin(), data.end());
    int index = 0;
    root = inOrderBST(root, data, index);

    return root;
}