#include<iostream>
using namespace std;
#define endl '\n'

int arr[1001];

int Eratos(int N,int K) {
	int cnt = 0;
	for (int i = 2; i <= N; i++) {
		int tmp;
		if (arr[i] == 0) {
			tmp = i;
			for (int j = tmp; j <= N; j += tmp) {
				if (arr[j] == -1)continue;
				else {
					arr[j] = -1;
					cnt++;
					if (cnt == K)
						return j;
				}
			}
		}
		else continue;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, k;
	cin >> n >> k;

	cout << Eratos(n, k) << endl;

	return 0;
}