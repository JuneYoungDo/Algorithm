#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;
ll N;
vector<ll> arr;
int main() {
	cin >> N;
	for (int i = 0; i < 10; i++) {
		arr.push_back(i);
	}
	ll chk = 1;
	do {
		if (!chk)
			break;
		if (arr[0] == 0 || arr[4] == 0)
			continue;
		ll a = 0, b = 0, dir[2][5] = { {0,1,2,2,3},{4,3,5,2,6} };
		for (int i = 0; i < 5; i++) {
			a *= 10;
			b *= 10;
			a += arr[dir[0][i]];
			b += arr[dir[1][i]];
		}
		if (a + b == N) {
			chk = 0;
			printf("%7d\n", a);
			printf("+%6d\n", b);
			printf("-------\n");
			printf("%7d\n", N);
		}
	} while (next_permutation(arr.begin(), arr.end()));
	if (chk)
		cout << "No Answer";
	return 0;
}