/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Function to find if BST contains dead end. Elements will be > 0.
// Dead End means, we are not able to insert any element after that node.
// Input :
//               8
//             /   \ 
//            7     10
//          /      /   \
//         2      9     13

// Output : Yes
// Explanation : We can't insert any element at
//               node 9.

bool isDeadEndHelper(Node* root, int start, int end) {
    if (root == NULL)
        return false;

    if (root->data - 1 == start and root->data + 1 == end)
        return true;

    bool leftSub = isDeadEndHelper(root->left, start, root->data);
    bool rightSub = isDeadEndHelper(root->right, root->data, end);

    return leftSub or rightSub;
}

bool isDeadEnd(Node *root) {
    return isDeadEndHelper(root, 0, INT_MAX);
}