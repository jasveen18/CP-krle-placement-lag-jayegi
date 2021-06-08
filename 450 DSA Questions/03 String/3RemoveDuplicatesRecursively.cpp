// T - O(N)
string removeConsecutiveCharacter(string S) {
    if (S.size() == 0)
        return "";

    char toCheck = S[0];
    string findSmallerSubProb = removeConsecutiveCharacter(S.substr(1));

    if (toCheck == findSmallerSubProb[0]) return findSmallerSubProb;
    else return toCheck + findSmallerSubProb;
}