// T - O(2*N)
// S - O(1)
bool isOneRotationOfAnother(string a, string b) {
	// Concatenate a with a.
	a = a + a;

	// Now check if b is substring of a
	if (a.find(b) != std::string::npos)
		return true;

	return false;
}