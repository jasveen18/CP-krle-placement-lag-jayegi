/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - populate next pointer for all nodes. The next pointer for every node should be set to point to inorder successor.
// Input:
//          10
//        /  \
//       8    12
//      /
//     3


// Output: 3->8 8->10 10->12 12->-1
/*
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *next;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};
*/

void populateNextHelper(Node* root, Node* &head, Node* &tail) {
    if (root == NULL)
        return;

    populateNextHelper(root->left, head, tail);

    // Operation
    if (head == NULL) {
        head = root;
        tail = root;
    } else {
        tail->next = root;
        tail = tail->next;
    }

    populateNextHelper(root->right, head, tail);
}

void populateNext(Node *root) {
    Node* head = NULL;
    Node* tail = NULL;

    populateNextHelper(root, head, tail);
    root = head;
    return;
}