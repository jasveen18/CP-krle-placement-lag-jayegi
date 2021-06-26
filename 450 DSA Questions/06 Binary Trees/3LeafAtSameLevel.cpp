/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Check if leaf nodes are at same level or not.
int checkHeight(Node* root, bool &isEqual) {
    if (root == NULL)
        return 0;

    int leftHeight = checkHeight(root->left, isEqual);
    int rightHeight = checkHeight(root->right, isEqual);

    // If it has both nodes, still height is not equal from both sides then wrong
    if (root->left and root->right and leftHeight != rightHeight)
        isEqual = false;

    return 1 + max(leftHeight, rightHeight);
}


bool checkSameLevel(Node *root) {
    bool isSameLevel = true;
    checkHeight(root, isSameLevel);

    return isSameLevel;
}