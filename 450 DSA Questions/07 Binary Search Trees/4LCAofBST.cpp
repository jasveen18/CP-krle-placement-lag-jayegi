/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Function to find the lowest common ancestor in a BST.

// Approach 1 - Optimized LCA of Binary Tree.
Node* LCA(Node *root, int n1, int n2) {
    // Case 1 - Root becomes null
    if (root == NULL)
        return NULL;

    // Case 2 - Dono chiz left side lie krre hai
    if (n1 < root->data and n2 < root->data)
        return LCA(root->left, n1, n2);

    // Case 3 - Dono chiz right side lie krre hai
    if (n1 > root->data and n2 > root->data)
        return LCA(root->right, n1, n2);

    // Case 4 - Ya toh koi ek node is equal to root, or dono chiz opposite sides hai
    // So, root will be the answer here.
    return root;
}


// Approach 2 - Same as Binary Tree ka LCA
Node* LCA(Node* root, int n1, int n2) {
    // Case 4 - not present
    if (root == NULL)
        return NULL;

    // Case 1 - Koi ek is equal to root
    if (n1 == root->data or n2 == root->data)
        return root;

    // Case 2 and 3 -
    Node* left = LCA(root->left, n1, n2);
    Node* right = LCA(root->right, n1, n2);

    // Case 2 - if dono side pe lie krra hai
    if (left and right)
        return root;

    // Case 3 - if koi ek side mila
    if (!left)
        return right;
    if (!right)
        return left;
}