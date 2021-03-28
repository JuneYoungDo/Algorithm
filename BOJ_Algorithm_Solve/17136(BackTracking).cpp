#include<iostream>
#include<algorithm>
#define endl '\n';
using namespace std;

int map[10][10];
int paperNum[6] = { 0,5,5,5,5,5 };
int answer = 99999999;
int nowCnt;
bool flag;

void dfs(int y, int x)
{
	if (x == 10)
	{
		dfs(y + 1, 0);
		return;
	}
	if (y == 10)
	{
		answer = min(answer, nowCnt);
		return;
	}
	if (!map[y][x])
	{
		dfs(y, x + 1);
		return;
	}

	for (int i = 5; i > 0; i--)
	{
		if (paperNum[i] <= 0 || x + i > 10 || y + i > 10)
			continue;

		flag = true;
		for (int j = 0; j < i; j++)
		{
			for (int m = 0; m < i; m++)
			{
				if (!map[y + j][x + m])
				{
					flag = false;
					break;
				}
			}
			if (!flag)
				break;
		}

		if (!flag)
			continue;

		for (int j = 0; j < i; j++)
			for (int m = 0; m < i; m++)
				map[y + j][x + m] = 0;

		paperNum[i]--;
		nowCnt++;

		dfs(y, x + i);

		for (int j = 0; j < i; j++)
			for (int m = 0; m < i; m++)
				map[y + j][x + m] = 1;

		paperNum[i]++;
		nowCnt--;

	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	bool ansFlag = false;

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
		{
			cin >> map[i][j];
			if (map[i][j])
				ansFlag = true;
		}

	dfs(0, 0);

	if (ansFlag)
	{
		if (answer == 99999999)
		{
			cout << -1 << endl;
		}
		else
			cout << answer << endl;
	}
	else
		cout << 0 << endl;

	return 0;
}