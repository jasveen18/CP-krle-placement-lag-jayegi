/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

// Approach 1 - Level Order Traversal
// O(N) Time | O(H) Space
void Solution::connect(TreeLinkNode* A) {
    if (A == NULL)
        return;

    queue<TreeLinkNode*> q;
    q.push(A);

    while (q.empty() == false) {
        int n = q.size();
        for (int i = 0; i < n; i++) {
            TreeLinkNode* curr = q.front(); q.pop();
            if (i < n - 1)
                curr->next = q.front();

            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
    }

    return;
}



// Approach 2 - Three Pointers
// T - O(N) | S - O(1)
void connect(TreeLinkNode* root) {
    TreeLinkNode* level_start = root;
    TreeLinkNode* end = root;
    TreeLinkNode* levelend = root;
    while (level_start) {
        if (level_start->left) {
            end->next = level_start->left;
            end = end->next;
        }
        if (level_start->right) {
            end->next = level_start->right;
            end = end->next;
        }
        if (level_start == levelend) {
            level_start = level_start->next;
            levelend->next = nullptr;
            levelend = end;
        }
        else {
            level_start = level_start->next;
        }
    }

}


void Solution::connect(TreeLinkNode* A) {
    TreeLinkNode *start = NULL, *prev = NULL;
    while (A) {
        if (A->left) {
            if (prev) prev->next = A->left;
            else start = A->left;
            prev = A->left;
        }
        if (A->right) {
            if (prev) prev->next = A->right;
            else start = A->right;
            prev = A->right;
        }
        if (A->next) A = A->next;
        else {
            A = start;
            start = NULL;
            prev = NULL;
        }
    }
}