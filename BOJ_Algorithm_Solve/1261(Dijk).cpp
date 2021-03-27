#include<iostream>
#include<vector>
#include<queue>
#include<string>
#define INF 99999999
#define endl '\n'
using namespace std;

struct moveXY
{
	int y, x;
};

int n, m;
int map[102][102];
int dist[102][102];
moveXY moving[4] = { {1,0},{0,1},{-1,0},{0,-1} };
priority_queue<pair<int, pair<int, int>>> pq;

void dijkstra(int y, int x)
{
	pq.push({ 0,{y,x} });
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
			if (nextY < 1 || nextX < 1 || nextY > n || nextX > m)
				continue;

			if (dist[nextY][nextX] != INF)
				continue;

			if (map[nextY][nextX])
				pq.push({ curW - 1,{nextY,nextX} });
			else pq.push({ curW,{nextY,nextX} });
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m >> n;

	for (int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;

		for (int j = 1; j <= m; j++)
			map[i][j] = s[j - 1] - '0';
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			dist[i][j] = INF;

	dijkstra(1, 1);

	cout << -dist[n][m] << endl;

	return 0;
}