/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - count number of nodes in BST that lie in the given range.

void inOrderTraversal(Node* root, int l, int h, int &ans) {
    if (root == NULL)
        return;

    inOrderTraversal(root->left, l, h, ans);

    if (root->data >= l and root->data <= h)
        ans++;

    inOrderTraversal(root->right, l, h, ans);
}

int getCount(Node *root, int l, int h) {
    int ans = 0;
    inOrderTraversal(root, l, h, ans);

    return ans;
}