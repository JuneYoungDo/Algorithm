#include<iostream>
#include<queue>
using namespace std;
#define endl '\n'

int arr[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int ans = 0;
	priority_queue<int> pq;
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		pq.push(-arr[i]);
	}
	while (pq.size()!=1) {
		int a = -pq.top();
		pq.pop();
		int b = -pq.top();
		pq.pop();
		ans = ans + a + b;
		pq.push(-(a + b));
	}
	cout << ans << endl;

	return 0;
}