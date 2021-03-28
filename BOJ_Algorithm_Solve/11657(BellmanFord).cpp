#include<iostream>
#include<queue>	
#include<vector>
using namespace std;

#define endl '\n'
#define ll long long
#define INF 99999999

int n, m;
ll dist[501];
ll cycle[501];
bool inQ[501];
vector<pair<int, int>> adj[501];
queue<int> q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		adj[from].push_back({ cost,to });
	}

	for (int i = 1; i <= n; i++)
		dist[i] = INF;

	dist[1] = 0;
	q.push(1);
	inQ[1] = true;
	cycle[1]++;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		inQ[cur] = false;
		for (int i = 0; i < adj[cur].size(); i++)
		{
			int next = adj[cur][i].second;
			int nCost = adj[cur][i].first;
			if (dist[next] > dist[cur] + nCost)
			{
				dist[next] = dist[cur] + nCost;
				if (!inQ[next])
				{
					q.push(next);
					inQ[next] = true;
					cycle[next]++;

					if (cycle[next] >= n)
					{
						cout << -1 << endl;
						return 0;
					}
				}
			}
		}
	}

	for (int i = 2; i <= n; i++)
	{
		if (dist[i] == INF)
			cout << -1 << endl;
		else
			cout << dist[i] << endl;
	}

	return 0;
}