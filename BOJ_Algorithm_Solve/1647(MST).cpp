#include<iostream>
#include<vector>
#include<algorithm>
#define endl '\n'
using namespace std;

int sum;
vector<pair<int, pair<int, int>>> edges;
vector<int> parent;
vector<int> ans;

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

	for (int i = 1; i <= v; i++)
		parent[i] = i;

	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edges.push_back({ c,{a,b} });
	}

	sort(edges.begin(), edges.end());

	for (int i = 0; i < edges.size(); i++)	// 마지막에 가장 큰 가중치를 갖는 집을 따로 떼어낸다
	{
		int cost = edges[i].first;
		int v1 = edges[i].second.first;
		int v2 = edges[i].second.second;

		if (findParent(v1) != findParent(v2))
		{
			Union(v1, v2);
			ans.push_back(cost);
		}
	}

	for (int i = 0; i < ans.size() - 1; i++)
		sum += ans[i];

	cout << sum << endl;

	return 0;
}