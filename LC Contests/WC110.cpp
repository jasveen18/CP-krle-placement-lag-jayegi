// 1. Reorder Logs
static bool orderorder(pair<string, string> a, pair<string, string> b) {
	bool first = (a.second[0] >= 'a' and a.second[0] <= 'z');
	bool second = (b.second[0] >= 'a' and b.second[0] <= 'z');

	if (first and !second)
		return true;
	if (!first and second)
		return false;

	if (first and second) {
		if (a.second == b.second)
			return a.first < b.first;

		return a.second < b.second;
	}

	return false;
}

vector<string> reorderLogFiles(vector<string>& logs) {
	// break the identifier and content
	// sort in place with letter logs at first and their order
	vector<pair<string, string>> divlogs;
	for (int i = 0; i < logs.size(); i++) {
		string identifier = "";

		for (int j = 0; j < logs[i].size(); j++) {
			if (logs[i][j] == ' ') {
				break;
			} else {
				identifier += logs[i][j];
			}
		}

		string content = logs[i].substr(identifier.size() + 1);
		divlogs.push_back({identifier, content});
	}

	stable_sort(divlogs.begin(), divlogs.end(), orderorder);

	for (int i = 0; i < divlogs.size(); i++) {
		logs[i] = divlogs[i].first + " " + divlogs[i].second;
	}

	return logs;
}