#include<iostream>
#include<algorithm>
#define endl '\n'
using namespace std;

int n, sum;
int dp[100001];
int arr[100001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sum = arr[0];
	dp[0] = arr[0];
	for (int i = 1; i < n; i++)
	{
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
		sum = max(sum, dp[i]);
	}
	cout << sum << endl;

	return 0;
}