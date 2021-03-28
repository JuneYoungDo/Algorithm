#include<iostream>
#include<string>
#define endl '\n'
#define max 9
using namespace std;

bool flag = false;
int map[max][max];
bool row[max][max];
bool col[max][max];
bool square[max][max];

void input();
void print();
void dfs(int cnt);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	dfs(0);

	return 0;
}

void input()
{
	for (int i = 0; i < max; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < s.length(); j++)
		{
			map[i][j] = s[j] - '0';
			if (map[i][j] != 0)
			{
				row[i][map[i][j]] = true;
				col[j][map[i][j]] = true;
				square[(i / 3) * 3 + (j / 3)][map[i][j]] = true;
			}
		}
	}
}

void print()
{
	for (int i = 0; i < max; i++)
	{
		{for (int j = 0; j < max; j++)
			cout << map[i][j];
		}
		cout << endl;
	}
}

void dfs(int cnt)
{
	if (flag == true)
		return;
	int x = cnt / max;
	int y = cnt % max;
	if (cnt == 81)
	{
		print();
		flag = true;
	}
	if (map[x][y] == 0)
	{
		for (int i = 1; i <= max; i++)
		{
			if (row[x][i] == false && col[y][i] == false && square[(x / 3) * 3 + (y / 3)][i] == false)
			{
				row[x][i] = true;
				col[y][i] = true;
				square[(x / 3) * 3 + (y / 3)][i] = true;
				map[x][y] = i;
				dfs(cnt + 1);
				row[x][i] = false;
				col[y][i] = false;
				square[(x / 3) * 3 + (y / 3)][i] = false;
				map[x][y] = 0;
			}
		}
	}
	else
		dfs(cnt + 1);
}