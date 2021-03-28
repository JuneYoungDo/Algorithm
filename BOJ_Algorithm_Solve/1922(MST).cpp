#include<iostream>
#include<vector>
#include<algorithm>
#define endl '\n'
using namespace std;

int N, M;
vector<int> parent;
vector<pair<int, pair<int, int>>> edges;

int findParent(int x)
{
	if (x == parent[x])return x;
	else return parent[x] = findParent(parent[x]);
}

void Union(int a, int b)
{
	int pa = findParent(a);
	int pb = findParent(b);
	if (pa < pb)
		parent[pb] = pa;
	else
		parent[pa] = pb;
}

int checkParent(int a, int b)
{
	a = findParent(a);
	b = findParent(b);
	if (a == b)return 1;
	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	parent.resize(N + 1);
	int sum = 0;

	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edges.push_back({ c,{a,b} });
	}
	sort(edges.begin(), edges.end());

	for (int i = 0; i <= N; i++)
	{
		parent[i] = i;
	}

	for (int i = 0; i < edges.size(); i++)
	{
		int cost = edges[i].first;
		int v1 = edges[i].second.first;
		int v2 = edges[i].second.second;
		if (!checkParent(v1, v2))
		{
			sum += cost;
			Union(v1, v2);
		}
	}
	cout << sum << endl;

	return 0;
}
