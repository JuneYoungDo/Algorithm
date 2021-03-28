#include<iostream>
#include<vector>
#include<cstring>
#define endl '\n'
using namespace std;

int N, M;
int answer = 0;
vector<int> v[1001];
int owner[1001];
int ownerWorkNum[1001] = { 0, };
bool visit[1001];

bool dfs(int curWorker);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		int num;
		cin >> num;
		if (num == 0)
			continue;
		for (int j = 1; j <= num; j++)
		{
			int tmp;
			cin >> tmp;
			v[i].push_back(tmp);
		}
	}
	for (int i = 1; i <= N; i++)
	{
		if (dfs(i))
			answer++;
		memset(visit, false, sizeof(visit));
	}
	for (int i = 1; i <= N; i++)
	{
		if (dfs(i))
			answer++;
		memset(visit, false, sizeof(visit));
	}
	cout << answer << endl;

	return 0;
}

bool dfs(int curWorker)
{
	if (visit[curWorker])return false;
	visit[curWorker] = true;

	for (int i = 0; i < v[curWorker].size(); i++)
	{
		int curTask = v[curWorker][i];
		if (owner[curTask] == curWorker)continue;
		if (owner[curTask] == false)
		{
			owner[curTask] = curWorker;
			return true;
		}
		else
		{
			if (dfs(owner[curTask]))
			{
				owner[curTask] = curWorker;
				return true;
			}
		}
	}
	return false;
}