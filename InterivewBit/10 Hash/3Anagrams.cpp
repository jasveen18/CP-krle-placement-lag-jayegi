/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Given an array of strings, return all groups of strings that are anagrams. Represent a group by a list of integers representing the index in the original list
vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    unordered_map<string, vector<int>> a;
    vector<vector<int>> res;

    int i = 1;
    for (auto el : A) {
        sort(el.begin(), el.end());
        a[el].push_back(i++);
    }

    for (auto el : a) {
        res.push_back(el.second);
    }

    return res;
}
