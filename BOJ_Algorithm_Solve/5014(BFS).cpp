#include<iostream>
#include<queue>
#define endl '\n'
#define max 3000001
using namespace std;

int map[max];
int F, S, G, U, D;

int bfs(int index)
{
	queue<int> q;
	q.push(index);
	map[index] = 0;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		if (cur == G)
			return map[cur];

		int next[2] = { cur + U,cur - D };

		for (int i = 0; i < 2; i++)
		{
			if (1 <= next[i] && next[i] <= F && map[next[i]] == -1)
			{
				map[next[i]] = map[cur] + 1;
				q.push(next[i]);
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

	cin >> F >> S >> G >> U >> D;

	for (int i = 0; i < max; i++)
		map[i] = -1;

	int ans = bfs(S);

	if (ans == -1)
		cout << "use the stairs" << endl;
	else
		cout << ans << endl;

	return 0;
}