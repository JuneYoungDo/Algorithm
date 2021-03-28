#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#define endl '\n'
using namespace std;

int sum1;
int sum2;
vector<pair<int, pair<int, int>>> tmp;
vector<pair<int, pair<int, int>>> edges;
vector<pair<int, pair<int, int>>> edges2;	// 최적 구할때 (내림차순)
vector<int> parent;

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

	int v, e;
	cin >> v >> e;
	parent.resize(v + 1);

	for (int i = 0; i <= v; i++)
		parent[i] = i;

	int a, b, c;
	cin >> a >> b >> c;
	edges.push_back({ c,{a,b} });
	edges2.push_back({ c,{a,b} });

	for (int i = 0; i < e; i++)
	{
		cin >> a >> b >> c;
		tmp.push_back({ c,{a,b} });
	}
	sort(tmp.begin(), tmp.end());

	for (int i = 0; i < tmp.size(); i++)
		edges.push_back(tmp[i]);

	for (int i = 0; i < edges.size(); i++)
	{
		int cost = edges[i].first;
		int v1 = edges[i].second.first;
		int v2 = edges[i].second.second;
		if (findParent(v1) != findParent(v2))
		{
			Union(v1, v2);
			sum2 += cost;
		}
	}

	for (int i = 0; i <= v; i++)
		parent[i] = i;

	for (int i = edges.size() - 1; i > 0; i--)
	{
		edges2.push_back(edges[i]);
	}

	for (int i = 0; i < edges2.size(); i++)
	{
		int cost = edges2[i].first;
		int v1 = edges2[i].second.first;
		int v2 = edges2[i].second.second;
		if (findParent(v1) != findParent(v2))
		{
			Union(v1, v2);
			sum1 += cost;
		}
	}
	int worstCase = pow(v - sum2, 2);
	int bestCase = pow(v - sum1, 2);
	cout << abs(worstCase - bestCase) << endl;

	return 0;
}