/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Function to insert at bottom without any other DS.
void insertAtBottom(stack<int> &st, int element) {
	// Base Case when stack is empty then insert
	if (st.empty()) {
		st.push(element);
		return;
	}

	// Recursive case to store the element after poping and pushing it back after operations
	int topEl = st.top(); st.pop();
	insertAtBottom(st, element);

	st.push(topEl);
	return;
}