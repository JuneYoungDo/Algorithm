#include<iostream>
#define endl '\n'
using namespace std;

int weight[31];
bool dp[31][15001];
int n, k;
bool check[8];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> weight[i];

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < 15001; j++)
		{
			if (!dp[i - 1][j])continue;
			if (j > weight[i])dp[i][j - weight[i]] = true;
			else dp[i][weight[i] - j] = true;
			dp[i][j + weight[i]] = true;
			dp[i][j] = true;
		}
		dp[i][weight[i]] = true;
	}

	cin >> k;

	for (int i = 0; i < k; i++)
	{
		int x;
		cin >> x;
		if (dp[n][x])
			check[i] = true;
	}

	for (int i = 0; i < k; i++)
	{
		if (check[i])cout << "Y" << ' ';
		else cout << "N" << ' ';
	}
	cout << endl;

	return 0;
}
