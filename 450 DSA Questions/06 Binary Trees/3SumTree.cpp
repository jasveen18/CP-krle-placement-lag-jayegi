/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Check if the root is equal to sum of its children for all the nodes.
int findSum(Node* root, bool &isEqual) {
    if (root == NULL)
        return 0;

    // Find sum of children
    int findSumLeft = findSum(root->left, isEqual);
    int findSumRight = findSum(root->right, isEqual);

    // If it is not a leaf node
    if (root->left != NULL or root->right != NULL)
        if (findSumLeft + findSumRight != root->data)
            isEqual = false;

    // Return the total sum till this node.
    return (findSumLeft + findSumRight) + root->data;
}

bool isSumTree(Node* root) {
    if (root == NULL)
        return true;

    bool isSum = true;
    findSum(root, isSum);

    return isSum;
}