#include<iostream>
#define endl '\n'
using namespace std;

bool arr[1000001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int m, n;
	arr[1] = true;
	cin >> m >> n;
	for (int i = 1; i * i <= n; i++)
	{
		if (arr[i])continue;
		for (int j = i * 2; j <= n; j += i)
		{
			arr[j] = true;
		}
	}
	for (int i = m; i <= n; i++)
		if (!arr[i])cout << i << endl;

	return 0;
}
