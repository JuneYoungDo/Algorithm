#include<iostream>
#include<queue>
#include<vector>
#define endl '\n'
#define INF 99999999
using namespace std;

vector<vector<pair<int, int>>> graph;
priority_queue<pair<int, int>> pq;
vector<int> visited;

void Dijkstra(int start)
{
	pq.push({ 0, start });
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

			if (visited[nextV] != INF)
				continue;

			pq.push({ nextW,nextV });
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int v, e, start;
	cin >> v >> e;
	cin >> start;

	graph.resize(v + 1);
	visited.resize(v + 1);

	for (int i = 0; i < e; i++)
	{
		int sv, ev, w;
		cin >> sv >> ev >> w;
		graph[sv].push_back({ -w,ev });
	}
	for (int i = 1; i <= v; i++)
		visited[i] = INF;


	Dijkstra(start);
	for (int i = 1; i <= v; i++)
	{
		if (visited[i] == INF)
		{
			cout << "INF" << endl;
		}
		else
			cout << -1 * visited[i] << endl;
	}

	return 0;
}