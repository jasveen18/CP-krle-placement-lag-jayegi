/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Find all the duplicates in a subtree.
// Same idea as check wala, we need to generate all the combinations of tree traversal.
string preOrder(Node *root, unordered_map<string, int> &countComb, vector<Node*> &ans) {
    string res = "";
    if (root == NULL) {
        res += "$";
        return res;
    }

    res += root->data;
    res += preOrder(root->left, countComb, ans);
    res += preOrder(root->right, countComb, ans);

    countComb[res]++;

    // If it becomes 2 then push krdo. We don't need to push for anything higher than this.
    if (countComb[res] == 2) {
        ans.push_back(root);
    }

    return res;
}


vector<Node*> printAllDups(Node* root) {
    unordered_map<string, int> countComb;
    vector<Node*> res;

    preOrder(root, countComb, res);
    return res;
}