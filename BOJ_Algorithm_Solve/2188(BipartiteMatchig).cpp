#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
#define endl '\n'

int N, M;
int ans = 0;
int cowHouse[201];
vector<int> v[201];
bool visit[201];

bool dfs(int nowCow)
{
	if (visit[nowCow])
		return false;

	visit[nowCow] = true;
	for (int i = 0; i < v[nowCow].size(); i++)
	{
		int findHouse = v[nowCow][i];//Áý

		if (cowHouse[findHouse] == 0 || dfs(cowHouse[findHouse]))
		{
			cowHouse[findHouse] = nowCow;
			return true;
		}
	}

	return false;
}

void matching()
{
	for (int i = 1; i <= N; i++)
	{
		if (dfs(i))
		{
			ans++;
		}
		memset(visit, false, sizeof(visit));
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		int n;
		cin >> n;
		for (int j = 0; j < n; j++)
		{
			int num;
			cin >> num;
			v[i].push_back(num);
		}
	}

	matching();

	cout << ans << endl;

	return 0;
}

