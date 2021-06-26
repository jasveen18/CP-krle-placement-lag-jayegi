/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Function to check whether a binary tree is balanced or not.
int heightOfTree(Node* root, bool &balance) {
    if (root == NULL)
        return 0;

    int leftHeight = heightOfTree(root->left, balance);
    int rightHeight = heightOfTree(root->right, balance);

    balance = balance and ((abs(leftHeight - rightHeight)) <= 1);
    return max(leftHeight, rightHeight) + 1;
}


bool isBalanced(Node *root) {
    bool isBalance = true;
    heightOfTree(root, isBalance);

    return isBalance;
}