#include<iostream>
#include<algorithm>
#include<vector>
#define endl '\n'
using namespace std;

int arr[1000001];
vector<int> dp;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	int ans = 1;
	dp.push_back(arr[0]);
	for (int i = 0; i < N; i++)
	{
		if (dp.back() < arr[i])
		{
			dp.push_back(arr[i]);
			ans++;
		}
		else
		{
			vector<int>::iterator iter = lower_bound(dp.begin(), dp.end(), arr[i]);
			dp[iter - dp.begin()] = arr[i];
		}
	}

	cout << ans << endl;

	return 0;
}