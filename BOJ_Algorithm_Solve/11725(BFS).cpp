#include<iostream>
#include<vector>
#include<queue>
using namespace std;

queue<int> q;
vector<int> node[100001];

int arr[100001];

void bfs()
{
	int cur;
	q.push(1);
	arr[1] = 1;
	while (!q.empty())
	{
		cur = q.front();
		q.pop();

		for (int i = 0; i < node[cur].size(); i++)
		{
			if (arr[node[cur][i]] == NULL)
			{
				q.push(node[cur][i]);
				arr[node[cur][i]] = cur;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n - 1; i++)
	{
		int u, c;
		cin >> u >> c;

		node[u].push_back(c);
		node[c].push_back(u);
	}

	bfs();

	for (int i = 2; i <= n; i++)
	{
		cout << arr[i] << '\n';
	}

	return 0;
}
