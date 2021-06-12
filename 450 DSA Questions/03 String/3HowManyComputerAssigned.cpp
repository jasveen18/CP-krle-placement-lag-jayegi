int computerAssigned(int n, string people) {
	// 0 means ni hai, 1 means hai, but no comp, 2 means comp
	vector<int> status(27, 0);
	int res = 0;
	int occupiedComputer = 0;

	for (int i = 0; i < people.size(); i++) {
		int charAs = people[i] - 'A';

		// Check conditions
		// If pehle baar aara
		if (status[charAs] == 0) {
			status[charAs] = 1;
			// PC dedo
			if (occupiedComputer < n) {
				occupiedComputer++;
				status[charAs] = 2;
			} else {
				res++;
			}
			// Jaane wala time
		} else {
			// If pc assigned tha toh lelo.
			if (status[charAs] == 2)
				occupiedComputer--;
			status[charAs] = 0;
		}
	}

	return res;
}