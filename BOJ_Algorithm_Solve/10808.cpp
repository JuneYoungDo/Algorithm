#include<iostream>
#include<string>
using namespace std;
#define endl '\n'

int arr[123];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string input;
	cin >> input;

	for (int i = 0; i < input.length(); i++) {
		int s = input[i];
		arr[s]++;
	}
	for (int i = 97; i < 123; i++)
		cout << arr[i] << " ";

	return 0;
}