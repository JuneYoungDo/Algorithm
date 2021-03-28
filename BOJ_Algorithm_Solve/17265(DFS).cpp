#include<iostream>	
using namespace std;
#define endl '\n';

int n;
char map[6][6];
int biggest = -9999999;
int lowest = 9999999;
int dx[2] = { 1,0 };
int dy[2] = { 0,1 };

void dfs(int x, int y, int ans, char before)
{
	for (int i = 0; i < 2; i++)
	{
		int mx = x + dx[i];
		int my = y + dy[i];

		if (mx <= n && my <= n)
		{
			if (map[mx][my] == '+')
				dfs(mx, my, ans, '+');
			else if (map[mx][my] == '-')
				dfs(mx, my, ans, '-');
			else if (map[mx][my] == '*')
				dfs(mx, my, ans, '*');
			else
			{
				int tmp = 0;
				if (before == '+')
					tmp = ans + (map[mx][my] - '0');
				else if (before == '-')
					tmp = ans - (map[mx][my] - '0');
				else if (before == '*')
					tmp = ans * (map[mx][my] - '0');

				if (mx == n - 1 && my == n - 1)
				{
					if (tmp < lowest)
						lowest = tmp;
					if (tmp > biggest)
						biggest = tmp;

					return;
				}

				dfs(mx, my, tmp, map[mx][my]);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];

	dfs(0, 0, map[0][0] - '0', map[0][0]);

	cout << biggest << ' ' << lowest << endl;

	return 0;
}