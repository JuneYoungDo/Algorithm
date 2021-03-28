#include<iostream>
#include<algorithm>
#define endl '\n'
using namespace std;

int n, sum;
int dp[501][501] = { 0, };
int arr[501][501] = { 0 , };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			cin >> arr[i][j];

	sum = 0;
	dp[1][1] = arr[1][1];

	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			dp[i][j] = max(dp[i - 1][j] + arr[i][j], dp[i - 1][j - 1] + arr[i][j]);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (sum < dp[n][i])
			sum = dp[n][i];
	}

	cout << sum << endl;

	return 0;
}