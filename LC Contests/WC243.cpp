/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/


// 1. 1880. Check if Word Equals Summation of Two Words
int convertToInt(string s) {
	int n = s.size();

	for (int i = 0; i < n; i++) {
		s[i] = s[i] - 'a' + '0';
	}

	return stoi(s);
}

bool isSumEqual(string firstWord, string secondWord, string targetWord) {
	int first = convertToInt(firstWord);
	int second = convertToInt(secondWord);
	int target = convertToInt(targetWord);

	if (first + second == target)
		return true;

	return false;
}


// 2. 1881. Maximum Value after Insertion
string maxValue(string n, int x) {
	bool sign = n[0] == '-';
	int size = n.size();
	string res = "";

	if (sign and n.size() == 1)
		return n;

	int i;

	// If negative that means first greater ke pehle
	if (sign) {
		i = 0; // Skipping the first element ('-')
		while (i < size - 1 and n[i + 1] - '0' <= x)
			i++;
	}

	else { // Else, first smaller ke pehle
		i = -1;
		while (i < size - 1 and n[i + 1] - '0' >= x)
			i++;
	}

	res = n.substr(0, i + 1);
	res += x + '0';
	res += n.substr(i + 1);

	return res;
}


// 3. 1882. Process Tasks Using Servers

// Here, we have two min heaps, ordered by [time, weight, index]: available and busy. First, we put all servers into the available heap
// with time equals to zero.

// As we process our tasks:

// Move servers that have finished (time <= t) from busy to avail.
// Pick the top server from the avail heap and move it to the busy heap with time = t + tasks[t].
// This is where we record the index of the server for that task.
// What happens if no servers are available? In this case, the server that is closest to finishing its task will pick up the new task. So:

// We move the top server from busy to avail heap.
// Then we move it back to the busy heap, but this time we extend the completion time for the duration of the new task time + task[t].
// In other words, the time is t + task[t] if we have an available server vs. time + task[t].

vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
	// [time, weight, index]
	priority_queue<array<long, 3>, vector<array<long, 3>>, greater<array<long, 3>>> available, busy;
	vector<int> res;

	for (int i = 0; i < servers.size(); i++) {
		available.push({0, servers[i], i});
	}

	for (long t = 0; t < tasks.size(); t++) {
		while (!busy.empty() and (busy.top()[0] <= t or available.empty())) {
			auto [time, weight, idx] = busy.top(); busy.pop();
			available.push({time <= t ? 0 : time, weight, idx});
		}

		auto [time, weight, idx] = available.top(); available.pop();
		busy.push({max(time, t) + tasks[t], weight, idx});
		res.push_back(idx);
	}

	return res;
}