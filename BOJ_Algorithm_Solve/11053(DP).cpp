#include<iostream>
#include<algorithm>
#define endl '\n'
using namespace std;

int arr[1001];
int dp[1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	for (int i = 0; i < N; i++)
	{
		dp[i] = 1;
		for (int j = 0; j < N; j++)
		{
			if (arr[i] > arr[j])
			{
				if (dp[i] < dp[j] + 1)
					dp[i] = dp[j] + 1;
			}
		}
	}
	int maxS = 0;
	for (int i = 0; i < N; i++)
		if (maxS < dp[i])
			maxS = dp[i];

	cout << maxS << endl;

	return 0;
}