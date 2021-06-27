/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Return the Kth smallest element in the given BST
void findKthSmallestNode(Node* root, int K, int &index, Node* &kth) {
    if (root == NULL)
        return;

    // Run only if we don't have an answer
    if (kth == NULL)
        findKthSmallestNode(root->left, K, index, kth);

    // Update the index and match with K.
    index++;
    if (index == K) {
        kth = root;
        return;
    }

    // Run only if we don't have an answer
    if (kth == NULL)
        findKthSmallestNode(root->right, K, index, kth);
}

int KthSmallestElement(Node *root, int K) {
    int index = 0;
    Node* KthSmallestNode = NULL;
    findKthSmallestNode(root, K, index, KthSmallestNode);

    if (KthSmallestNode)
        return KthSmallestNode->data;
    else
        return -1;
}