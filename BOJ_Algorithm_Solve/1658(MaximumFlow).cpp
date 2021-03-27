#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

#define endl '\n'
#define INF 99999999
#define sink 1102
#define maxn 1104

int M, N;
int ans;
int minFlow;
vector<int> v[maxn];
int capacity[maxn][maxn];
int flow[maxn][maxn];
int prevNode[maxn];
vector<int> share[maxn];

bool bfs()
{
	memset(prevNode, -1, sizeof(prevNode));
	queue<int> q;
	q.push(0);
	while (!q.empty())
	{
		int current = q.front();
		q.pop();

		if (current == sink)
			return true;

		for (int i = 0; i < v[current].size(); i++)
		{
			int next = v[current][i];
			if (prevNode[next] == -1 && capacity[current][next] - flow[current][next] > 0)
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

		minFlow = INF;
		for (int i = sink; i != 0; i = prevNode[i])
			minFlow = min(minFlow, capacity[prevNode[i]][i] - flow[prevNode[i]][i]);

		for (int i = sink; i != 0; i = prevNode[i])
		{
			flow[prevNode[i]][i] += minFlow;
			flow[i][prevNode[i]] -= minFlow;
		}
		ans += minFlow;
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M >> N;

	for (int i = 101; i <= 100 + M; i++)
	{
		v[i].push_back(sink);
		v[sink].push_back(i);

		cin >> capacity[i][sink];
	}

	for (int i = 1; i <= N; i++)
	{
		int num;
		cin >> num;

		for (int j = 0; j < num; j++)
		{
			int a;
			cin >> a;
			int A = a + 100;

			v[i].push_back(A);
			v[A].push_back(i);
			capacity[i][A] += INF;

			share[A].push_back(i);
		}
		int val;
		cin >> val;

		v[0].push_back(i);
		v[i].push_back(0);
		capacity[0][i] = val;
	}

	for (int i = 101; i <= 100 + M; i++)
	{
		if (share[i].size() <= 1)
			continue;

		int e = share[i][0];
		for (int j = 1; j < share[i].size(); j++)
		{
			int s = share[i][j];

			v[s].push_back(e);
			v[e].push_back(s);
			capacity[s][e] = INF;
		}
	}
	maximumFlow();

	cout << ans << endl;

	return 0;
}