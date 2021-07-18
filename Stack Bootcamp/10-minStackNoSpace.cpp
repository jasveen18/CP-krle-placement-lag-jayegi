// ** Min Element Stack with No Extra Space ** //

// Problem Statement ->
// Implement min stack in O(1) time and O(1) space.

// Ek normal stack to chaiye for main stack and ek minElement variable hoga.
// Ek mechanism chaiye jisse abhi ke min element se agar isko pop krte hai toh pichla pe chale gye

// Push krte time, do case hai -> minel >= wala element aayega, toh normal push kr do
// minel < wala element aayega, agar aisa hai toh ek flag raise kro, -> push a modified data -> (2 * val) - minel.

// Anamoly jaisa ho jaega, jab milega wo anamoly tb phir previous element le lenge.
// Yaad rakhne wali chiz lag ri hai, koi aisa logic ni hai ki aage use hoga.
class MinStackNoSpace {
	int minElement;
	stack<int> main;

	MinStackNoSpace() {
		minElement = INT_MAX;
	}

	void pushElement(int val) {
		if (main.empty()) {
			main.push(val);
			minElement = val;
		}

		else {
			if (main.top() >= minElement)
				main.push(val);
			else {
				// Create an anamoly and store in stack
				main.push(2 * val - minElement);

				// Store the real min element value in variable
				minElement = val;
			}
		}
	}

	void popElement() {
		if (main.empty())
			return;

		if (main.top() >= minElement)
			main.pop();
		else { // Anamoly detect hua, mtlb minEl change hoga yaha. Yaha pe minElement se bhi minimum hai
			minElement = 2 * minElement - main.top();
			main.pop();
		}
	}

	int topElement() {
		if (main.empty())
			return -1;

		if (main.top() >= minElement)
			return main.top();
		else {
			return 2 * minElement - main.top();
		}
	}

	int getMin() {
		if (main.empty())
			return -1;

		return minElement;
	}
}