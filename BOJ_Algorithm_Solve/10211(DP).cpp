#include<iostream>
#include<algorithm>
#define endl '\n';
using namespace std;

int testcase;
int subArr[1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> testcase;

	while (testcase--)
	{
		int n;
		cin >> n;


		for (int i = 1; i <= n; i++)
		{
			int x;
			cin >> x;

			subArr[i] = subArr[i - 1] + x;
		}

		int result = -9999999;
		for (int i = 1; i <= n; i++)
		{
			for (int j = i; j <= n; j++)
			{
				result = max(result, subArr[j] - subArr[i - 1]);
			}
		}

		cout << result << endl;
	}


	return 0;
}