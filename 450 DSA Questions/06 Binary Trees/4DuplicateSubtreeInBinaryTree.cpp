/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Check whether there is a duplicate subtree.

// Generate all the possible combinations of traversals.
// Then check if kisi ka occurance is more than once.
string preOrder(Node *root, unordered_map<string, int> &countComb) {
    string res = "";
    if (root == NULL) {
        res += "$";
        return res;
    }

    res += root->data;
    res += preOrder(root->left, countComb);
    res += preOrder(root->right, countComb);

    countComb[res]++;
    return res;
}


bool isDuplicateSubtree(Node *root) {
    unordered_map<string, int> countComb;
    preOrder(root, countComb);

    // Check if ek single node na ho.
    for (auto el : countComb) {
        if (el.second > 1 and el.first.size() > 3)
            return true;
    }

    return false;
}