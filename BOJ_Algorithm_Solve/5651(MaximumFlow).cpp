#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;

#define endl '\n'
#define INF 99999999
#define maxn 302

int N, M;
int ans, minFlow;
vector<int> graph[maxn];
vector<pair<int, int>> tmp;
int capacity[maxn][maxn];
int flow[maxn][maxn];
int prevNode[maxn];

bool bfs(int source, int sink)
{
	memset(prevNode, 0, sizeof(prevNode));
	queue<int> q;
	q.push(source);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		if (cur == sink)
			return true;

		for (int i = 0; i < graph[cur].size(); i++)
		{
			int next = graph[cur][i];

			if (prevNode[next] == 0 && capacity[cur][next] - flow[cur][next] > 0)
			{
				q.push(next);
				prevNode[next] = cur;
			}
		}
	}
	return false;
}
void maximumFlow()
{
	while (1)
	{
		if (!bfs(1, N))
			break;

		minFlow = INF;
		for (int i = N; i != 1; i = prevNode[i])
			minFlow = min(minFlow, capacity[prevNode[i]][i] - flow[prevNode[i]][i]);

		for (int i = N; i != 1; i = prevNode[i])
		{
			flow[prevNode[i]][i] += minFlow;
			flow[i][prevNode[i]] -= minFlow;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testcase;
	cin >> testcase;

	while (testcase--)
	{
		cin >> N >> M;

		int source = 1;
		int sink = N;

		memset(graph, 0, sizeof(graph));
		memset(capacity, 0, sizeof(capacity));
		memset(flow, 0, sizeof(flow));
		tmp.clear();

		for (int i = 0; i < M; i++)
		{
			int a, b, c;
			cin >> a >> b >> c;

			graph[a].push_back(b);
			graph[b].push_back(a);

			capacity[a][b] += c;

			tmp.push_back({ a,b });			// 실제 간선 정보들 따로 확보
		}

		maximumFlow();						// 최대유량 구해주고,

		ans = 0;

		for (int i = 0; i < tmp.size(); i++)			// 완전 중요 간선인지 확인
		{												// 조건 2가지 , 유량 == 용량 && 다른길로 돌아가는 길이 없어야 함
			int sp = tmp[i].first;
			int ep = tmp[i].second;

			memset(prevNode, -1, sizeof(prevNode));

			queue<int> q;
			q.push(sp);

			while (!q.empty())
			{
				int cur = q.front();
				q.pop();

				if (prevNode[ep] != -1)							// 정점 도착하면 끝
					break;

				for (int k = 0; k < graph[cur].size(); k++)
				{
					int next = graph[cur][k];
					if (prevNode[next] == -1 && capacity[cur][next] - flow[cur][next] > 0)		// 다른길로 돌아갈 수 있는지 확인
					{
						q.push(next);
						prevNode[next] = cur;
					}
				}
			}

			if (prevNode[ep] == -1)						// 도착하지 못했다 == 다른길로 돌아갈 수 없다
				ans++;
		}

		// 6트 오류 코드
		//for (int i = 1; i <= N; i++)
		//{
		//	for (int j = 0; j < graph[i].size(); j++)
		//	{
		//		int nextR = graph[i][j];

		//		if (capacity[i][nextR] == flow[i][nextR])
		//		{
		//			if (capacity[i][nextR] == 0)				// 가짜 간선
		//				continue;

		//			memset(prevNode, -1, sizeof(prevNode));
		//			queue<int> q;
		//			q.push(i);

		//			while (!q.empty())
		//			{
		//				int cur = q.front();
		//				q.pop();

		//				if (cur == nextR)
		//					break;

		//				for (int k = 0; k < graph[cur].size(); k++)
		//				{
		//					int next = graph[cur][k];
		//					if (prevNode[next] == -1 && capacity[cur][next] - flow[cur][next] > 0)
		//					{
		//						q.push(next);
		//						prevNode[next] = cur;
		//					}
		//				}
		//			}

		//			if (prevNode[nextR] == -1)
		//				ans++;
		//		}
		//	}
		//}

		cout << ans << endl;
	}

	return 0;
}