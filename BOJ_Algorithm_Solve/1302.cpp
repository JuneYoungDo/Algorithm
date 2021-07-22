#include<iostream>
#include<map>
#include<string>
using namespace std;
#define endl '\n'

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	map<string, int> bookStore;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		if (bookStore.count(s)) {
			bookStore[s]++;
		}
		else
			bookStore.insert({ s,1 });
	}
	string ans;
	int max = 0;
	for (auto itr = bookStore.begin(); itr != bookStore.end(); itr++) {
		if (itr->second > max) {
			max = itr->second;
			ans = itr->first;
		}
	}
	cout << ans << endl;

	return 0;
}