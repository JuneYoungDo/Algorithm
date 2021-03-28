#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
#define endl '\n'
using namespace std;

struct moving
{
	int y, x;
};

int col, row;
char map[60][60];
int check[60][60];
moving arr[4] = { {1,0},{0,1},{-1,0},{0,-1} };
int bfs(int y, int x);
void reset();

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> col >> row;

	for (int i = 0; i < col; i++)
		for (int j = 0; j < row; j++)
			check[i][j] = 0;

	for (int i = 0; i < col; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < row; j++)
		{
			map[i][j] = s[j];
		}
	}

	int answer = 0;
	for (int i = 0; i < col; i++)
		for (int j = 0; j < row; j++)
		{
			reset();
			if (map[i][j] == 'L')
				answer = max(answer, bfs(i, j));
		}
	cout << answer << endl;

	return 0;
}
void reset()
{
	for (int i = 0; i < col; i++)
		for (int j = 0; j < row; j++)
			check[i][j] = 0;
}

int bfs(int y, int x)
{
	queue<pair<int, int>> q;
	int result = 0;

	q.push(make_pair(y, x));
	check[y][x] = 1;

	while (!q.empty())
	{
		int nowY = q.front().first;
		int nowX = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextY = nowY + arr[i].y;
			int nextX = nowX + arr[i].x;

			result = max(result, check[nowY][nowX]);
			if (0 <= nextY && nextY < col && 0 <= nextX && nextX < row)
				if (map[nextY][nextX] == 'L' && check[nextY][nextX] == 0)
				{
					q.push(make_pair(nextY, nextX));
					check[nextY][nextX] = check[nowY][nowX] + 1;
				}
		}
	}
	return result - 1;
}