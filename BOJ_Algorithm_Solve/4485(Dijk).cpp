#include<iostream>
#include<vector>
#include<queue>
#include<string>
#define INF 9999999
#define endl '\n'
using namespace std;

struct moveXY
{
	int y, x;
};

int n;
int map[127][127];
int dist[127][127];
moveXY moving[4] = { {1,0},{0,1},{-1,0},{0,-1} };
priority_queue<pair<int, pair<int, int>>> pq;

void dijkstra(int start, int y, int x)
{
	pq.push({ start,{y,x} });
	while (!pq.empty())
	{
		int curY = pq.top().second.first;
		int curX = pq.top().second.second;
		int curW = pq.top().first;
		pq.pop();

		if (dist[curY][curX] != INF)
			continue;
		dist[curY][curX] = curW;

		for (int i = 0; i < 4; i++)
		{
			int nextY = curY + moving[i].y;
			int nextX = curX + moving[i].x;
			if (nextY < 0 || nextX < 0 || nextY >= n || nextX >= n)
				continue;

			int nextW = map[nextY][nextX] + curW;

			if (dist[nextY][nextX] != INF)
				continue;

			pq.push({ nextW,{nextY,nextX } });
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cnt = 0;

	while (1)
	{
		cin >> n;
		if (n == 0)
			break;

		cnt++;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				int x;
				cin >> x;
				map[i][j] = -x;
				dist[i][j] = INF;
			}

		dijkstra(map[0][0], 0, 0);

		cout << "Problem " << cnt << ": " << -dist[n - 1][n - 1] << endl;
	}

	return 0;
}