/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Function to check whether a Binary Tree is BST or not.
// Check the possible range.
bool isBSTHelper(Node* root, int left, int right) {
    if (root == NULL)
        return true;

    if (root->data <= left or root->data >= right)
        return false;

    bool leftSubprob = isBSTHelper(root->left, left, root->data);
    bool rightSubprob = isBSTHelper(root->right, root->data, right);

    return leftSubprob and rightSubprob;
}

bool isBST(Node* root) {
    int left = INT_MIN, right = INT_MAX;
    return isBSTHelper(root, left, right);
}