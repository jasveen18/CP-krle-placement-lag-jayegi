/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Return the size of the largest sub-tree which is also a BST
// v[0] -> size of largest BST
// v[1] -> if current node is BST or not
// v[2] -> max element from left subtree
// v[3] -> min element from right subtree

vector<int> findLargestBST(Node* root) {
    // Base Case
    if (root == NULL) {
        return {0, 1, INT_MIN, INT_MAX}; // Null node is a BST with 0 nodes and range pura number line hoga.
    }

    // Check for leaf node
    int currVal = root->data;
    if (root->left == NULL and root->right == NULL)
        return {1, 1, currVal, currVal};

    vector<int> leftData = findLargestBST(root->left);
    vector<int> rightData = findLargestBST(root->right);

    // Extract information
    int maxSubTree = max(leftData[0], rightData[0]);
    int minFromRight = rightData[3];
    int maxFromLeft = leftData[2];

    // If left or right is not bst or current ka data is out of bounds
    if (leftData[1] == 0 or rightData[1] == 0 or currVal <= maxFromLeft or currVal >= minFromRight)
        return {maxSubTree, 0, -1, -1};

    // If sab shii hai toh phir ye BST hai, return the data correcly.
    return {1 + leftData[0] + rightData[0], 1, max({currVal, leftData[2], rightData[2]}), min({currVal, leftData[3], rightData[3]})};
}


int largestBst(Node *root) {
    vector<int> res = findLargestBST(root);
    return res[0];
}