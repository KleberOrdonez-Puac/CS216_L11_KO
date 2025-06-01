#include "helper.h"

void ClearInputError() {
	if (cin.fail()) {
		cin.clear();
	}
	if (cin.peek() == '\n') {
		cin.ignore(BUFFER_SIZE, '\n');
	}
}
string SetUpper(string rhs) {
    for (int i = 0; i < rhs.length(); i++) {
        rhs[i] = toupper(rhs[i]);
    }
    return rhs;
}
string GetString(string prompt) {
	string input = "";
	cout << "\n\n" << prompt;

	ClearInputError();
	getline(cin, input);

	return input;
}
int GetNum(string prompt) {
	int input = 0;
	cout << "\n\n" << prompt;

	ClearInputError();
	while (!(cin >> input)) {
		ClearInputError();
		cout << "\nInvalid input.\n" << prompt;
	}

	return input;
}
int GiveRanVal(int minVal, int maxVal) {
    return (rand() % (maxVal - minVal + 1) + minVal);
}
