#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define N 1001

bool visit[N] = { 0, };
vector<int>list[N];
int ans = 0;

void dfs(int index)
{
	if (visit[index] != true)
	{
		visit[index] = true;
	}
	for (int i = 0; i < list[index].size(); i++)
	{
		if (visit[list[index][i]] != true)
			dfs(list[index][i]);
	}
	ans++;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int computer, line;
	cin >> computer >> line;

	for (int i = 0; i < line; i++)
	{
		int num, num2;
		cin >> num >> num2;
		list[num].push_back(num2);
		list[num2].push_back(num);
	}

	/*for (int i = 1; i <= computer; i++)
	{
		sort(list[i].begin(), list[i].end());
	}*/

	dfs(1);
	cout << ans - 1 << '\n';

	return 0;
}