/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Check if the root is equal to sum of its children for all the nodes.
int findSum(Node* root, int &maxSum) {
    if (root == NULL)
        return 0;

    // Find sum of children
    int findSumLeft = findSum(root->left, isEqual);
    int findSumRight = findSum(root->right, isEqual);

    // Total sum here
    int currSum = root->data + findSumLeft + findSumRight;

    // Take max
    maxSum = max(maxSum, currSum);

    // Return the total sum till this node.
    return currSum;
}

bool maxSumTree(Node* root) {
    if (root == NULL)
        return 0;

    int maxSum = 0;
    findSum(root, maxSum);

    return maxSum;
}