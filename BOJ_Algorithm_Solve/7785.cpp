#include<iostream>
#include<string>
#include<map>
using namespace std;
#define endl '\n'


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	map<string, bool> company;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string name;
		string inOut;
		cin >> name >> inOut;

		if (company.count(name)) {
			if (inOut == "enter")
				company[name] = true;
			else if (inOut == "leave")
				company[name] = false;
		}
		else {
			if(inOut == "enter")
				company.insert({ name, true });
		}
	}
	for (auto itr = --company.end(); itr != --company.begin(); itr--) {
		if (itr->second == true)
			cout << itr->first << endl;
		else
			continue;
	}

	return 0;
}