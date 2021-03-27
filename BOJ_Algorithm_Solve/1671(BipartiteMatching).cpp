#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

#define endl '\n'

struct info
{
	int size;
	int speed;
	int intel;
	info()
	{
		size = 0;
		speed = 0;
		intel = 0;
	}
};

int N;
int ans;
vector<info> v;
vector<int> shark[51];
bool visit[51];
int eat[51];

bool dfs(int cur)
{
	if (visit[cur])
		return false;

	visit[cur] = true;
	for (int i = 0; i < shark[cur].size(); i++)
	{
		int feed = shark[cur][i];

		/*if (visit[feed])
			continue;

		visit[feed] = true;*/

		if (eat[feed] == 0 || dfs(eat[feed]))
		{
			eat[feed] = cur;
			return true;
		}
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	v.resize(N + 1);

	for (int i = 1; i <= N; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		v[i].size = a;
		v[i].speed = b;
		v[i].intel = c;
	}

	for (int i = 1; i <= N - 1; i++)
	{
		for (int j = i + 1; j <= N; j++)
		{
			if (v[i].size == v[j].size && v[i].speed == v[j].speed && v[i].intel == v[j].intel)
				shark[i].push_back(j);
			else if (v[i].size >= v[j].size && v[i].speed >= v[j].speed && v[i].intel >= v[j].intel)
				shark[i].push_back(j);
			else if (v[i].size <= v[j].size && v[i].speed <= v[j].speed && v[i].intel <= v[j].intel)
				shark[j].push_back(i);
		}
	}
	int k = 2;
	while (k--)
	{
		for (int i = 1; i <= N; i++)
		{
			memset(visit, false, sizeof(visit));
			if (dfs(i))
			{
				ans++;
			}
		}
	}
	cout << N - ans << endl;

	return 0;
}