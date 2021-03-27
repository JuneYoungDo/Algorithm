#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define INF 99999999
#define endl '\n'
using namespace std;

vector<vector<pair<int, int>>> graph;
priority_queue<pair<int, int>> pq;
vector<int> visited;
vector<int> ans;

void Dijkstra(int start)
{
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
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int v, e, endv;
	cin >> v >> e >> endv;

	graph.resize(v + 1);
	visited.resize(v + 1);
	ans.resize(v + 1);

	for (int i = 0; i < e; i++)
	{
		int sv, ev, w;
		cin >> sv >> ev >> w;
		graph[sv].push_back({ -w,ev });
	}

	for (int i = 1; i <= v; i++)
	{
		if (i == endv)
			continue;

		for (int j = 1; j <= v; j++)
		{
			visited[j] = INF;
		}

		Dijkstra(i);
		ans[i] = -visited[endv];

		for (int j = 1; j <= v; j++)
		{
			visited[j] = INF;
		}
		Dijkstra(endv);
		ans[i] += (-visited[i]);
	}

	sort(ans.begin(), ans.end());

	cout << ans[v] << endl;

	return 0;
}