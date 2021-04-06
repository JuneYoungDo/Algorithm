#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
#define endl '\n'
#define INF 99999999
#define source 0
#define sink 201

int n, m;
int totalCnt, totalSal;
vector<int> graph[202];
int capacity[202][202];
int sendCost[202][202];
int flow[202][202];
int prevNode[202];
int dist[202];
int cycle[202];
bool inQ[202];

void spfa()
{
	memset(prevNode, -1, sizeof(prevNode));
	memset(inQ, false, sizeof(inQ));

	for (int i = source; i <= sink; i++)
		dist[i] = INF;

	dist[source] = 0;
	queue<int> q;
	q.push(source);
	inQ[source] = true;
//	cycle[source]++;			// 무한루프 돌 가능성이 없는 문제이기에 꼭 필요하진 않음
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		inQ[cur] = false;
		for (int i = 0; i < graph[cur].size(); i++)
		{
			int next = graph[cur][i];
			if (capacity[cur][next] - flow[cur][next]>0 && dist[next] > dist[cur] + sendCost[cur][next])
			{
				dist[next] = dist[cur] + sendCost[cur][next];
				prevNode[next] = cur;

				if (!inQ[next])
				{
					q.push(next);
					inQ[next] = true;

					/*cycle[next]++;
					if (cycle[next] >= n)
						return;*/
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
		capacity[i][sink] += x;
		
		graph[i].push_back(sink);
		graph[sink].push_back(i);
	}
	for (int i = 101; i <= 100 + m; i++)
	{
		int x;
		cin >> x;
		capacity[source][i] += x;

		graph[source].push_back(i);
		graph[i].push_back(source);
	}
	for (int i = 101; i <= 100+m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int x;
			cin >> x;
			capacity[i][j] += x;

			graph[i].push_back(j);
			graph[j].push_back(i);
		}
	}
	for (int i = 101; i <= m + 100; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> sendCost[i][j];
			sendCost[j][i] = -sendCost[i][j];
		}
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

			totalSal += minFlow * sendCost[prevNode[i]][i];
		}
		totalCnt += minFlow;
	}

	cout << totalCnt << endl;
	cout << totalSal << endl;

	return 0;
}