#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;

#define endl '\n'
#define INF 99999999
#define source 0
#define sink 801

int n, m;
int ansCnt, ansPay;
vector<pair<int, int>> graph[802];
int capacity[802][802];
int flow[802][802];
int prevNode[802];
int cycle[802], dist[802];
bool inQ[802];

void spfa()
{
	memset(prevNode, -1, sizeof(prevNode));
	memset(inQ, false, sizeof(inQ));
	//	memset(cycle, 0, sizeof(cycle));
	for (int i = 1; i <= sink; i++)
		dist[i] = INF;

	dist[source] = 0;
	queue<int> q;
	q.push(source);
	inQ[source] = true;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		inQ[cur] = false;
		for (int i = 0; i < graph[cur].size(); i++)
		{
			int next = graph[cur][i].second;
			int nCost = graph[cur][i].first;

			if (capacity[cur][next] > flow[cur][next] && dist[next] > dist[cur] + nCost)
			{
				dist[next] = dist[cur] + nCost;
				prevNode[next] = cur;
				if (!inQ[next])
				{
					q.push(next);
					inQ[next] = true;
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		for (int j = 0; j < x; j++)
		{
			int work, sal;
			cin >> work >> sal;
			graph[i].push_back({ -sal,work + 400 });		// 최대치 -> - 붙여서 구하고 다시 - 붙이면 끝
			graph[work + 400].push_back({ sal,i });
			capacity[i][work + 400] = 1;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		graph[source].push_back({ 0,i });
		graph[i].push_back({ 0,source });
		capacity[source][i] = 1;
	}

	for (int i = 401; i <= 400 + m; i++)
	{
		graph[i].push_back({ 0,sink });
		graph[sink].push_back({ 0,i });
		capacity[i][sink] = 1;
	}

	while (1)
	{
		spfa();
		if (prevNode[sink] == -1)
			break;
		int minFlow = INF;
		for (int i = sink; i != source; i = prevNode[i])
		{
			minFlow = min(minFlow, capacity[prevNode[i]][i] - flow[prevNode[i]][i]);
		}
		for (int i = sink; i != source; i = prevNode[i])
		{
			flow[prevNode[i]][i] += minFlow;
			flow[i][prevNode[i]] -= minFlow;
		}

		ansCnt += minFlow;
		ansPay += dist[sink];
	}

	cout << ansCnt << endl;
	cout << -ansPay << endl;

	return 0;
}