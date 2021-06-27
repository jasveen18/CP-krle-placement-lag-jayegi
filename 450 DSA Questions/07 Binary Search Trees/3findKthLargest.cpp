/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Return the Kth largest element in the given BST
void findKthLargestNode(Node* root, int K, int &index, Node* &kth) {
    if (root == NULL)
        return;

    // Run only if we don't have an answer
    if (kth == NULL)
        findKthLargestNode(root->right, K, index, kth);

    // Update the index and match with K.
    index++;
    if (index == K) {
        kth = root;
        return;
    }

    // Run only if we don't have an answer
    if (kth == NULL)
        findKthLargestNode(root->left, K, index, kth);
}


int kthLargest(Node *root, int K) {
    Node* kthLargestNode = NULL;

    int index = 0;
    findKthLargestNode(root, K, index, kthLargestNode);

    if (kthLargestNode)
        return kthLargestNode->data;
    else
        return -1;
}