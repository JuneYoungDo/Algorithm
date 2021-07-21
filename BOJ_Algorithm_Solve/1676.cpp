#include<iostream>
#include<cmath>
using namespace std;
#define endl '\n'
#define ll long long

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int input;
	cin >> input;
	int ans = 0;

	for (int i = 1; i <= input; i++) {
		if (i % 125 == 0)
			ans += 3;
		else if (i % 25 == 0)
			ans += 2;
		else if (i % 5 == 0)
			ans++;
	}

	cout << ans << endl;

	return 0;
}