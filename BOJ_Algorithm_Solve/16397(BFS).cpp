#include<iostream>
#include<queue>
#include<utility>
using namespace std;
#define endl '\n';

int n, t, g;
bool visit[100001];
queue<pair<int, int>> q;

int bfs()
{
	while (!q.empty())
	{
		int num = q.front().first;
		int count = q.front().second;

		q.pop();

		if (count > t)
			break;
		if (num == g)
			return count;

		// A버튼
		if (num + 1 < 100000 && visit[num + 1] == false)
		{
			visit[num + 1] = true;
			q.push(make_pair(num + 1, count + 1));
		}

		if (num != 0 && num * 2 < 100000)
		{
			int tmp = 0;
			if (num * 2 / 10000 != 0)
				tmp = 10000;
			else if (num * 2 / 1000 != 0)
				tmp = 1000;
			else if (num * 2 / 100 != 0)
				tmp = 100;
			else if (num * 2 / 10 != 0)
				tmp = 10;
			else
				tmp = 1;

			// B버튼
			if (num * 2 - tmp < 100000)
			{
				visit[num * 2 - tmp] = true;
				q.push(make_pair(num * 2 - tmp, count + 1));
			}
		}
	}

	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> t >> g;
	q.push(make_pair(n, 0));
	visit[n] = true;

	int ans = bfs();

	if (ans == -1)
	{
		cout << "ANG" << endl;
	}
	else
		cout << ans << endl;


	return 0;
}