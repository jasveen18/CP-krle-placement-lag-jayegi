/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Reverse a stack without using while or for loops. Only recursion is allowed
void insertAtBottom(stack<int> &st, int element) {
	if (st.empty()) {
		st.push(element);
		return;
	}

	int topEl = st.top(); st.pop();
	insertAtBottom(st, element);

	st.push(topEl);
	return;
}

void reverseStack(stack<int> &st) {
	if (st.empty())
		return;

	int topEl = st.top(); st.pop();
	reverseStack(st);

	insertAtBottom(st, topEl);
	return;
}