#include<iostream>
#include<math.h>
#define Max 123456
using namespace std;

int che[Max * 2] = { 0, };

void Erasto(int x)
{
	che[1] = 1;

	for (int i = 2; i < sqrt(2 * Max); i++)
	{
		if (che[i] == 0)
		{
			che[i] = 0;
			for (int j = i + 1; j <= 2 * Max; j++)
			{
				if (j % i == 0)
				{
					che[j] = 1;
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	Erasto(Max);

	while (1)
	{
		int x;
		cin >> x;

		if (x == 0)
			break;
		else
		{
			int answer = 0;
			for (int i = x + 1; i <= 2 * x; i++)
			{
				if (che[i] == 0)
				{
					answer++;
				}
			}
			cout << answer << '\n';
		}
	}

	return 0;
}