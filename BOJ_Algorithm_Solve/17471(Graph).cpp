#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
#define endl '\n';

int n;
int answer = 99999999;
int num[11];
bool isConnect[11][11];
bool visit[11];
bool isSelect[11];

// 선거구 끼리 모두 연결 되어 있는가?
bool isConnected(vector<int> v, bool flag)
{
	memset(visit, false, sizeof(visit));
	queue<int> q;
	q.push(v[0]);
	int cnt = 1;
	visit[v[0]] = true;

	while (!q.empty())
	{
		int front = q.front();
		q.pop();

		for (int i = 1; i <= n; i++)
		{
			// 두 구간이 연결, 다음 구간이 같은 분류인지, 방문하지 않았는지
			if (isConnect[front][i] == true && isSelect[i] == flag && visit[i] == false)
			{
				visit[i] = true;
				cnt++;
				q.push(i);
			}
		}
	}
	if (v.size() == cnt)
		return true;

	return false;
}

// 선거구가 한개 이상인지, 서로 모두 연결되어 있는지
bool check()
{
	vector<int> v1, v2;
	for (int i = 1; i <= n; i++)
	{
		if (isSelect[i])
			v1.push_back(i);
		else
			v2.push_back(i);
	}

	if (v1.size() == 0 || v2.size() == 0)
		return false;
	if (isConnected(v1, true) == false)
		return false;
	if (isConnected(v2, false) == false)
		return false;

	return true;
}

void diff()
{
	int a = 0;
	int b = 0;

	for (int i = 1; i <= n; i++)
	{
		if (isSelect[i])
			a += num[i];
		else
			b += num[i];
	}
	int diff = abs(a - b);
	answer = min(answer, diff);
}

void dfs(int idx, int cnt)
{
	if (cnt > 0)
	{
		if (check())
			diff();
	}

	for (int i = idx; i <= n; i++)
	{
		if (isSelect[i])
			continue;
		isSelect[i] = true;
		dfs(i, cnt + 1);
		isSelect[i] = false;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> num[i];
	}
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;

		for (int j = 0; j < x; j++)
		{
			int y;
			cin >> y;
			isConnect[i][y] = true;
			isConnect[y][i] = true;
		}
	}

	dfs(1, 0);

	if (answer == 99999999)
	{
		cout << -1 << endl;
	}
	else
		cout << answer << endl;

	return 0;
}