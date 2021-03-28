#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
#define endl '\n';
#define INF 99999999;

int N, M;
int dist[1001];
int par[1001];
vector<pair<int, int>> v[1001];

void Dijkstra(int start)
{
	for (int i = 1; i <= N; i++)
		dist[i] = INF;
	dist[start] = 0;

	priority_queue<pair<int, int>> PQ;
	PQ.push(make_pair(0, start));

	while (PQ.empty() == 0)
	{
		int cost = -PQ.top().first;
		int cur = PQ.top().second;
		PQ.pop();

		for (int i = 0; i < v[cur].size(); i++)
		{
			int next = v[cur][i].first;
			int tmp = v[cur][i].second;

			if (dist[next] > cost + tmp)
			{
				dist[next] = cost + tmp;
				par[next] = cur;
				PQ.push(make_pair(-dist[next], next));
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back(make_pair(b, c));
		v[b].push_back(make_pair(a, c));
	}

	Dijkstra(1);
	cout << N - 1 << endl;
	for (int i = 2; i <= N; i++)
	{
		cout << par[i] << " " << i << endl;
	}


	return 0;
}