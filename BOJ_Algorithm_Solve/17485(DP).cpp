#include<iostream>
#include<algorithm>
#define endl '\n'
#define INF 99999999
using namespace std;

int N, M;
int arr[1001][1001] = { INF, };
int dp[1001][1001][3] = { INF, };

void reset();

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	reset();

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> arr[i][j];

	for (int i = 1; i <= M; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			dp[1][i][j] = arr[1][i];
		}
	}

	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (j == 1)
			{
				dp[i][j][1] = min(dp[i - 1][j][0], dp[i - 1][j][2]) + arr[i][j];
				dp[i][j][2] = min(dp[i - 1][j + 1][0], dp[i - 1][j + 1][1]) + arr[i][j];
			}
			else if (j == M)
			{
				dp[i][j][0] = min(dp[i - 1][j - 1][1], dp[i - 1][j - 1][2]) + arr[i][j];
				dp[i][j][1] = min(dp[i - 1][j][0], dp[i - 1][j][2]) + arr[i][j];
			}
			else
			{
				dp[i][j][0] = min(dp[i - 1][j - 1][1], dp[i - 1][j - 1][2]) + arr[i][j];
				dp[i][j][1] = min(dp[i - 1][j][0], dp[i - 1][j][2]) + arr[i][j];
				dp[i][j][2] = min(dp[i - 1][j + 1][0], dp[i - 1][j + 1][1]) + arr[i][j];
			}
		}
	}
	int minS = INF;
	for (int i = 0; i <= M; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (dp[N][i][j] < minS)
				minS = dp[N][i][j];
		}
	}

	cout << minS << endl;

	return 0;
}

void reset()
{
	for (int i = 0; i < 1001; i++)
	{
		for (int j = 0; j < 1001; j++)
		{
			arr[i][j] = INF;
			for (int k = 0; k < 3; k++)
				dp[i][j][k] = INF;
		}
	}
}