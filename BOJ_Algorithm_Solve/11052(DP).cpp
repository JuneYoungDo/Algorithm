#include<iostream>
#include<algorithm>
#define endl '\n'
using namespace std;

int N;
int arr[1001];
int maxarr[1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	arr[0] = maxarr[0] = 0;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			maxarr[i] = max(maxarr[i - j] + arr[j], maxarr[i]);
		}
	}
	cout << maxarr[N] << endl;

	return 0;
}