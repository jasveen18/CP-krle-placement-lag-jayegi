/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Sort a stack using recursion
void insertAtCorrectPosition(stack<int> &st, int element) {
	if (st.empty() or st.top() <= element) {
		st.push(element);
		return;
	}

	int topEl = st.top(); st.pop();
	insertAtCorrectPosition(st, element);

	st.push(topEl);
	return;
}


void sortStack(stack<int> &st) {
	if (st.empty())
		return;

	int topEl = st.top(); st.pop();
	sortStack(st);

	insertAtCorrectPosition(st, topEl);

	return;
}