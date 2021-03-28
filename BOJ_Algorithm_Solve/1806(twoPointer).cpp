#include <iostream>
#include <algorithm>
using namespace std;
int arr[100001];
const int INF = 987654321;
int main(void)
{

	int N, S;
	int length = INF;
	int low = 0;
	int high = 0;
	int sum = 0;
	cin >> N >> S;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sum = arr[0];

	while (low <= high && high < N) {
		if (sum < S) {
			sum += arr[++high];
		}
		else if (sum == S) {
			length = min(length, (high - low + 1));
			sum += arr[++high];
		}
		else if (sum > S) {
			length = min(length, (high - low + 1));
			sum -= arr[low];
			low++;
		}
	}

	if (length == INF)
		cout << 0 << endl;
	else
		cout << length << endl;
	return 0;
}