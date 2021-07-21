#include<iostream>
#include<string>
using namespace std;
#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {
		int arr[4] = { 0, };
		string input;
		getline(cin, input);
		if (input == "")
			break;
		for (int i = 0; i < input.length(); i++) {
			int inp = input[i];
			if (65 <= inp && inp <= 90)arr[1]++;
			else if (97 <= inp && inp <= 122)arr[0]++;
			else if (0 <= input[i] - '0' && input[i] - '0' <= 9)arr[2]++;
			else arr[3]++;
		}
		for (int i : arr)cout << i << " ";
		cout << endl;
	}
	return 0;
}