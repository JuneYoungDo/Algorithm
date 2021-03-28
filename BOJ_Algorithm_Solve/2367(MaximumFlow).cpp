#include<iostream>	
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;

#define endl '\n'
#define INF 99999999
#define sink 302

int N, K, D;
int ans;
int minFlow;
vector<int> v[310];
int capacity[310][310];
int flow[310][310];
int prevNode[310];
int amount[310];

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

		//minFlow = INF;
		//for (int i = sink; i != 0; i = prevNode[i])
		//minFlow = min(minFlow, capacity[prevNode[i]][i] - flow[prevNode[i]][i]);

		for (int i = sink; i != 0; i = prevNode[i])
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

	cin >> N >> K >> D;

	for (int i = 201; i <= 200 + D; i++)
	{
		cin >> capacity[i][sink];
	}

	//	source 연결
	for (int i = 1; i <= N; i++)
	{
		v[0].push_back(i);
		v[i].push_back(0);
		capacity[0][i] += K;
		capacity[i][0] += 0;
	}
	//	sink 연결
	for (int i = 201; i <= 200 + D; i++)
	{
		v[i].push_back(sink);
		v[sink].push_back(i);
	}

	for (int i = 1; i <= N; i++)
	{
		int x;
		cin >> x;
		for (int j = 0; j < x; j++)
		{
			int y;
			cin >> y;
			int Y = y + 200;
			v[i].push_back(Y);
			v[Y].push_back(i);
			capacity[i][Y] += 1;
			capacity[Y][i] += 0;
		}
	}

	maximumFlow();

	cout << ans << endl;

	return 0;
}