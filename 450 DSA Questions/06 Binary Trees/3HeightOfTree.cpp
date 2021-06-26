/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Function to find the height of a binary tree.
int heightOfTree(struct Node* node) {
    // Base Case
    if (node == NULL)
        return 0;

    // Recursive Case
    int heightLeft = heightOfTree(node->left);
    int heightRight = heightOfTree(node->right);

    return max(heightLeft, heightRight) + 1;
}