#include<iostream>
#include<vector>
#include<algorithm>
#define endl '\n'
using namespace std;

int n, m, k;
int ans;
vector<int> light;
vector<int> parent;
vector<pair<int, pair<int, int>>> edges;

int findParent(int x)
{
	if (parent[x] == x)return x;
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

	cin >> n >> m >> k;

	parent.resize(n + 1);
	light.resize(k + 1);

	for (int i = 0; i < n; i++)
		parent[i] = i;

	for (int i = 0; i < k; i++)
	{
		cin >> light[i];
	}

	for (int i = 0; i < k - 1; i++)
	{
		int v1 = light[i];
		int v2 = light[i + 1];
		Union(v1, v2);
	}

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edges.push_back({ c,{a,b} });
	}
	sort(edges.begin(), edges.end());

	int num = k;

	for (int i = 0; i < edges.size(); i++)
	{
		int cost = edges[i].first;
		int v1 = edges[i].second.first;
		int v2 = edges[i].second.second;

		if (findParent(v1) != findParent(v2))
		{
			Union(v1, v2);
			ans += cost;
			num++;
		}
		if (num == n)
			break;
	}

	cout << ans << endl;

	return 0;
}