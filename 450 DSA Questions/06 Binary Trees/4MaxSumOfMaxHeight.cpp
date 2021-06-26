
/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - find the sum of all nodes on the longest path from root to leaf node.

// Top Down Approach - Not bottom up as the others.
void findHeight(Node* root, vector<int> &res, int height, int currSum) {
    // We have reached the end
    if (root == NULL) {
        // Update the max
        if (res[0] <= height) {
            res[0] = height;
            res[1] = currSum;
        }
        return;
    }

    // Try to find the answers in both children
    findHeight(root->left, res, height + 1, currSum + root->data);
    findHeight(root->right, res, height + 1, currSum + root->data);
    return;
}

int sumOfLongRootToLeafPath(Node *root) {
    if (root == NULL)
        return 0;

    // 1. First el is height, and second is sum.
    vector<int> res(2);
    res[0] = 0;
    res[1] = 0;

    findHeight(root, res, 0, 0);

    return res[1];
}