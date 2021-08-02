// 1. 929. Unique Email Addresses
int numUniqueEmails(vector<string>& emails) {
    unordered_map<string, unordered_set<string>> originals;
    // vector<string, string> split;

    // Split each mail into name and domain
    for (int i = 0; i < emails.size(); i++) {
        int rate = 0;
        while (emails[i][rate] != '@')
            rate++;

        string name = emails[i].substr(0, rate);
        string domain = emails[i].substr(rate + 1, emails[i].size() - rate);

        // Now that I have this, I need to clean the name
        string clean = "";
        for (int x = 0; x < name.size(); x++) {
            if (name[x] == '.')
                continue;
            if (name[x] == '+')
                break;

            clean += name[x];
        }

        originals[domain].insert(clean);
    }

    int res = 0;
    for (auto el : originals) {
        res += el.second.size();
    }

    return res;
}