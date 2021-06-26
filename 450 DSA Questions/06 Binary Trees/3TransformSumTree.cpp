/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Convert a given tree to a tree where every node contains sum of values of
// nodes in left and right subtrees in the original tree
int findSum(Node* node) {
    if (node == NULL)
        return 0;

    int leftSum = findSum(node->left);
    int rightSum = findSum(node->right);

    int currSum = leftSum + rightSum + node->data;
    node->data = leftSum + rightSum;

    return currSum;
}

void toSumTree(Node *node) {
    findSum(node);
}