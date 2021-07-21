#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string input;
	vector<string> ans;
	cin >> input;
	for (int i = 0; i < input.length(); i++) {
		ans.push_back(input.substr(i,input.length()-i));
	}
	sort(ans.begin(), ans.end());

	for (string s : ans) {
		cout << s << endl;
	}

	return 0;
}