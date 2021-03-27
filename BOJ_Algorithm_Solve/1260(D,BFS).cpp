#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#define max 1001
using namespace std;

int V, E, start;
vector<int> graph[max];
bool visit[max] = { 0, };
queue<int> q;

void reset()
{
	for (int i = 0; i < max; i++)
	{
		visit[i] = 0;
	}
}

void DFS(int index)
{
	if (visit[index] == false)
	{
		cout << index << ' ';
		visit[index] = true;
	}
	for (int i = 0; i < graph[index].size(); i++)
	{
		if (visit[graph[index][i]] == false)
			DFS(graph[index][i]);
	}
}
void BFS(int index)
{
	q.push(index);
	while (!q.empty())
	{
		int check = q.front();
		q.pop();
		if (visit[check] == true)
			continue;
		cout << check << " ";
		visit[check] = true;
		for (int i = 0; i < graph[check].size(); i++)
		{
			if (visit[graph[check][i]] == false)
				q.push(graph[check][i]);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> V >> E >> start;

	for (int i = 0; i < E; i++)
	{
		int a, b;
		cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i = 1; i <= V; i++)
	{
		sort(graph[i].begin(), graph[i].end());
	}

	DFS(start);
	cout << '\n';
	reset();
	BFS(start);

	return 0;
}