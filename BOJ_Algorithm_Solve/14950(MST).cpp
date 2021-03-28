#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct _KS_ {
	int from;
	int to;
	int val;
}KS;

vector<KS> edge;

int chk[10002];
int ret;

bool comp(KS a, KS b)
{
	return a.val < b.val;
}

int find(int num)
{
	if (num == chk[num])
		return num;

	return chk[num] = find(chk[num]);
}

int main()
{
	int n, m, t;
	cin >> n >> m >> t;

	for (int i = 1; i <= n; i++)
		chk[i] = i;

	for (int i = 0; i < m; i++)
	{
		KS ks;

		cin >> ks.from >> ks.to >> ks.val;

		edge.push_back(ks);
	}

	sort(edge.begin(), edge.end(), comp);

	int cnt = 0;
	for (int i = 0; i < m; i++)
	{
		int nv = find(edge[i].from);
		int nw = find(edge[i].to);

		if (nv == nw)
			continue;

		chk[nv] = nw;

		ret += edge[i].val + t * (cnt++);
	}

	cout << ret;
	return 0;
}