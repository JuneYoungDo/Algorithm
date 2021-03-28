#include<iostream>
#include<vector>
#include<algorithm>
#define endl '\n'
#define ll long long
using namespace std;

int n, m;
ll ans;
vector<pair<ll, pair<int, int>>> edges;
vector<int> parent;
char gender[1001];

int findParent(int x)
{
	if (parent[x] == x)return x;
	else return parent[x] = findParent(parent[x]);
}

void Union(int a, int b)
{
	int pa = findParent(a);
	int pb = findParent(b);

	if (pa < pb)parent[pb] = pa;
	else parent[pa] = pb;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	parent.resize(n + 1);

	for (int i = 1; i <= n; i++)
		cin >> gender[i];

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edges.push_back({ c,{a,b} });
	}

	sort(edges.begin(), edges.end());

	for (int i = 1; i <= n; i++)
		parent[i] = i;

	for (int i = 0; i < edges.size(); i++)
	{
		int cost = edges[i].first;
		int v1 = edges[i].second.first;
		int v2 = edges[i].second.second;

		if (findParent(v1) != findParent(v2) && gender[v1] != gender[v2])
		{
			Union(v1, v2);
			ans += cost;
		}
	}

	bool flag = true;
	for (int i = 2; i <= n; i++)
	{
		if (findParent(1) != findParent(i))
			flag = false;
	}

	if (flag)
		cout << ans << endl;
	else
		cout << -1 << endl;

	return 0;
}