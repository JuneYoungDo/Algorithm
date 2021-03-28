#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;

#define endl '\n'
#define INF 99999999

int N, P;
int ans;
int minFlow;
vector<vector<int>> road;
int capacity[401][401];
int flow[401][401];
int prevNode[401];

bool bfs()
{
	memset(prevNode, 0, sizeof(prevNode));
	queue<int> q;
	q.push(1);
	while (!q.empty())
	{
		int current = q.front();
		q.pop();

		if (current == 2)
			return true;

		for (int i = 0; i < road[current].size(); i++)
		{
			int next = road[current][i];
			if (prevNode[next] == 0 && capacity[current][next] - flow[current][next] > 0)
			{
				q.push(next);
				prevNode[next] = current;
			}
		}
	}

	return false;
}

void maximumFlow()
{
	while (1)
	{
		if (!bfs())
			break;

		/*minFlow = INF;
		for (int i = 2; i != 1; i = prevNode[i])
			minFlow = min(minFlow, capacity[prevNode[i]][i] - flow[prevNode[i]][i]);*/

		for (int i = 2; i != 1; i = prevNode[i])
		{
			flow[prevNode[i]][i] += 1;
			flow[i][prevNode[i]] -= 1;
		}

		ans += 1;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> P;
	road.resize(N + 1);

	for (int i = 0; i < P; i++)
	{
		int s, e;
		cin >> s >> e;
		road[s].push_back(e);
		road[e].push_back(s);
		capacity[s][e] += 1;
		capacity[e][s] += 0;
	}
	maximumFlow();

	cout << ans << endl;

	return 0;
}