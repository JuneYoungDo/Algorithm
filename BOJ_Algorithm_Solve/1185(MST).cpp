#include<iostream>
#include<vector>
#include<algorithm>
#define endl '\n'
using namespace std;

int n, m;
int ans;
vector<pair<int, pair<int, int>>> edges;
vector<int> parent;
vector<int> city;

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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	parent.resize(n + 1);
	city.resize(n + 1);

	for (int i = 1; i <= n; i++)
		parent[i] = i;

	for (int i = 1; i <= n; i++)
		cin >> city[i];

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		int cost = c + c + city[a] + city[b];

		edges.push_back({ cost,{a,b} });
	}

	sort(edges.begin(), edges.end());

	for (int i = 0; i < edges.size(); i++)
	{
		int cost = edges[i].first;
		int v1 = edges[i].second.first;
		int v2 = edges[i].second.second;

		if (findParent(v1) != findParent(v2))
		{
			Union(v1, v2);
			ans += cost;
		}
	}
	sort(city.begin(), city.end());

	cout << ans + city[1] << endl;

	return 0;
}