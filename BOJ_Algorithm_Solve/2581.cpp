#include<iostream>
#define MAX 10001
using namespace std;

int main()
{
	int M, N;
	cin >> M >> N;

	int che[MAX] = { 0, };
	che[1] = 1;
	for (int i = 2; i < 10001; i++)
	{
		if (che[i] == 0)
		{
			che[i] = 0;
			for (int j = i + 1; j < MAX; j++)
			{
				if (j % i == 0)
				{
					che[j] = 1;
				}
			}
		}
	}

	int answer = 0;
	for (int i = M; i <= N; i++)
	{
		if (che[i] == 0)
		{
			answer = i;
			break;
		}
	}

	if (answer == 0)
		cout << -1 << '\n';

	else
	{
		int sum = 0;
		for (int i = M; i <= N; i++)
		{
			if (che[i] == 0)
				sum += i;
		}
		cout << sum << '\n';

		cout << answer << '\n';
	}

	return 0;
}