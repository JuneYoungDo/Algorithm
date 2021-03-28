#include<iostream>
#include<vector>
#include<cstring>
#define endl '\n'
using namespace std;

int N, M, K;
int answer = 0;
vector<int> v[10001];
int owner[10001];
bool visit[10001];

bool dfs(int curWorker)
{
	if (visit[curWorker])
		return false;

	visit[curWorker] = true;
	for (int i = 0; i < v[curWorker].size(); i++)
	{
		int curTask = v[curWorker][i];
		if (owner[curTask] == 0 || dfs(owner[curTask]))
		{
			owner[curTask] = curWorker;
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

	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++)
	{
		int num;
		cin >> num;
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

	bool flag = true;
	while (K > 0 && flag)
	{
		for (int i = 1; i <= N; i++)
		{
			memset(visit, false, sizeof(visit));
			if (dfs(i))
			{
				flag = true;
				answer++;
				K--;
				break;
			}
			else
			{
				flag = false;
			}
		}
	}
	cout << answer << endl;

	return 0;
}
