#include<iostream>
#include<string>
using namespace std;
#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string input;
	getline(cin, input);
	for (int i = 0; i < input.length(); i++) {
		int ch = input[i];
		if (65 <= ch && ch <= 90) {
			ch = ch + 13;
			if (ch > 90)ch = ch - 90 + 65 -1;
			input[i] = ch;
		}
		else if (97 <= ch && ch <= 122) {
			ch = ch + 13;
			if (ch > 122)ch = ch - 122 + 97 -1;
			input[i] = ch;
		}
		else
			continue;
	}
	cout << input << endl;

	return 0;
}