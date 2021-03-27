#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define INF 99999999
#define endl '\n'
using namespace std;

int v, e;
vector<vector<pair<int, int>>> graph;
priority_queue<pair<int, int>> pq;
vector<int> visited;

int Dijkstra(int start, int end)
{
	for (int i = 1; i <= v; i++)
		visited[i] = INF;

	pq.push({ 0,start });
	while (!pq.empty())
	{
		int curV = pq.top().second;
		int curW = pq.top().first;
		pq.pop();

		if (visited[curV] != INF)continue;
		visited[curV] = curW;

		for (int i = 0; i < graph[curV].size(); i++)
		{
			int nextV = graph[curV][i].second;
			int nextW = graph[curV][i].first + curW;

			if (visited[nextV] != INF)continue;
			pq.push({ nextW,nextV });
		}
	}
	if (visited[end] == INF)
		return -1;

	return -visited[end];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> v >> e;

	graph.resize(v + 1);
	visited.resize(v + 1);

	for (int i = 0; i < e; i++)
	{
		int sv, ev, w;
		cin >> sv >> ev >> w;
		graph[sv].push_back({ -w,ev });
		graph[ev].push_back({ -w,sv });
	}
	int v1, v2;
	cin >> v1 >> v2;

	int r1 = Dijkstra(1, v1); // v1
	int r2 = Dijkstra(v1, v2); // v2
	int r3 = Dijkstra(v2, v); // v;

	int ans1 = 0;
	int ans2 = 0;
	bool flag1 = true;
	bool flag2 = true;

	if (r1 == -1 || r2 == -1 || r3 == -1)
		flag1 = false;
	else
		ans1 = r1 + r2 + r3;

	r1 = Dijkstra(1, v2); // v2
	r2 = Dijkstra(v2, v1); // v1
	r3 = Dijkstra(v1, v); // v;

	if (r1 == -1 || r2 == -1 || r3 == -1)
		flag2 = false;
	else
		ans2 = r1 + r2 + r3;

	if (flag1 || flag2)
		cout << min(ans1, ans2) << endl;
	else
		cout << -1 << endl;

	return 0;
}