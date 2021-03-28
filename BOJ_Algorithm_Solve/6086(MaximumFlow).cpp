#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
#define endl '\n'
#define INF 99999999

int n;
int minFlow;
int ans;
vector<int> pipe[53];
int capacity[53][53];	// 용량
int flow[53][53];	// 현재 흐르는 유량
int prevNode[53];	// 이전 노드	

int transNum(char x)
{
	if (x <= 'Z')
		return x - 'A' + 1;
	else
		return x - 'a' + 27;
}

bool bfs()
{
	memset(prevNode, 0, sizeof(prevNode));
	queue<int> q;
	q.push(1);
	while (!q.empty())
	{
		int current = q.front();
		q.pop();
		if (current == 26)
			return true;		// Z 도착
		for (int i = 0; i < pipe[current].size(); i++)
		{
			int next = pipe[current][i];
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

		minFlow = INF;

		for (int i = 26; i != 1; i = prevNode[i])
			minFlow = min(minFlow, capacity[prevNode[i]][i] - flow[prevNode[i]][i]);

		for (int i = 26; i != 1; i = prevNode[i])
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

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		char a, b;
		int cap;
		cin >> a >> b >> cap;
		int S = transNum(a);
		int E = transNum(b);
		pipe[S].push_back(E);
		pipe[E].push_back(S);
		capacity[S][E] += cap;
		capacity[E][S] += cap;
	}
	maximumFlow();

	cout << ans << endl;

	return 0;
}