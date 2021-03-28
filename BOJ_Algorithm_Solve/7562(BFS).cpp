#include<iostream>
#include<queue>
#define endl '\n'
#define INF 9999999
using namespace std;

struct movingKnight
{
	int x, y;
};

int testcase;
int squaresize;
int startX, startY;
int destinationX, destinationY;
queue<pair<int, int>> q;
int square[300][300];
bool visit[300][300];
movingKnight arr[8] = { {-2,-1 }, {-1, -2}, {1, -2}, {2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1} };


int bfs(int x, int y, int destinationX, int destinationY, int squaresize);
void reset(int x);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> testcase;

	while (testcase--)
	{
		cin >> squaresize;
		cin >> startX >> startY;
		cin >> destinationX >> destinationY;

		reset(squaresize);

		cout << bfs(startX, startY, destinationX, destinationY, squaresize) << endl;
	}

	return 0;
}

void reset(int x)
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < x; j++)
		{
			square[i][j] = INF;
			visit[i][j] = false;
		}
	}
	while (!q.empty())
		q.pop();
}

int bfs(int x, int y, int destinationX, int destinationY, int squaresize)
{
	q.push(make_pair(x, y));
	square[x][y] = 0;

	while (!q.empty())
	{
		pair<int, int> curPoint = q.front();
		q.pop();
		if (curPoint.first == destinationX && curPoint.second == destinationY)
			return square[curPoint.first][curPoint.second];

		for (int i = 0; i < 8; i++)
		{
			int nextX = curPoint.first + arr[i].x;
			int nextY = curPoint.second + arr[i].y;

			if (0 <= nextX && nextX < squaresize && 0 <= nextY && nextY < squaresize)
			{
				if (!visit[nextX][nextY])
				{
					q.push(make_pair(nextX, nextY));
					visit[nextX][nextY] = true;

					square[nextX][nextY] = square[curPoint.first][curPoint.second] + 1;
				}
			}
		}
	}
}
