#include<iostream>
using namespace std;
#define endl '\n'

int N,M;
int arr[100003];
int subSum[100003];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	subSum[1] = arr[1];
	for (int i = 2; i <= N; i++)
		subSum[i] = subSum[i - 1] + arr[i];

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		cout << subSum[b] - subSum[a-1] << endl;
	}


	return 0;
}