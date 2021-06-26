/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Return True if the given trees are isomotphic. Else return False.
// https://practice.geeksforgeeks.org/problems/check-if-tree-is-isomorphic/1#
bool isIsomorphic(Node *root1, Node *root2) {
    // Base Case -
    if (root1 == NULL and root2 == NULL)
        return true;

    if (root1 == NULL or root2 == NULL)
        return false;

    if (root1->data != root2->data)
        return false;

    bool answer = false;

    // Check for nodes same taraf hai
    answer |= isIsomorphic(root1->left, root2->left) and isIsomorphic(root1->right, root2->right);
    // Check for nodes swapped
    answer |= isIsomorphic(root1->left, root2->right) and isIsomorphic(root1->right, root2->left);

    return answer;
}