#include<iostream>
#define endl '\n'
#define ll long long
using namespace std;

int N;
ll dp[31][31] = { 0, };
ll dfs(ll all, ll half)
{
	if (dp[all][half])
		return dp[all][half];

	if (all == 0)
		return 1;

	dp[all][half] = dfs(all - 1, half + 1);

	if (half > 0)
		dp[all][half] += dfs(all, half - 1);

	return dp[all][half];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1)
	{
		cin >> N;
		if (N == 0)
			break;

		cout << dfs(N, 0) << endl;
	}

	return 0;
}