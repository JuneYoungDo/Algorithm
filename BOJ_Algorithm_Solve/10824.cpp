#include<iostream>
#include<string>
using namespace std;
#define endl '\n'
#define ll long long

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string a, b, c, d;
	cin >> a >> b >> c >> d;
	ll first = stoll(a + b);
	ll second = stoll(c + d);
	
	cout << first + second << endl;

	return 0;
}