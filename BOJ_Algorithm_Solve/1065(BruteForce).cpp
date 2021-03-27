#include<iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int num = 100;
	int ans = 99;
	int arr[3] = { 0, };

	if (n <= 99)
	{
		cout << n << '\n';
	}
	else
	{
		while (1)
		{
			if (num > n)
			{
				break;
			}
			else
			{
				arr[0] = num / 100;
				arr[1] = (num % 100) / 10;
				arr[2] = (num % 100) % 10;

				if (arr[2] - arr[1] == arr[1] - arr[0])
				{
					ans++;
				}
				else if (arr[0] - arr[1] == arr[1] - arr[2])
				{
					ans++;
				}
			}
			num++;
		}
		cout << ans << '\n';
	}

	return 0;
}