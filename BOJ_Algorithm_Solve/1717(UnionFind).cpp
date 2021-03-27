#include<iostream>
using namespace std;
#define MAX 1000001

int parent[MAX];

int FindParent(int x)
{
	if (x == parent[x])
		return x;
	else
	{
		int y = FindParent(parent[x]);
		parent[x] = y;
		return y;
	}
}
void Union(int x, int y)
{
	int px = FindParent(x);
	int py = FindParent(y);

	parent[py] = px;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i <= n; i++)
	{
		parent[i] = i;
	}
	int op, a, b;
	while (m--)
	{
		cin >> op >> a >> b;

		if (op == 0)
			Union(a, b);
		else
		{
			int ap = FindParent(a);
			int bp = FindParent(b);

			if (ap == bp)
				cout << "YES" << '\n';
			else
				cout << "NO" << '\n';
		}
	}

	return 0;
}