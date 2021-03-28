#include <iostream>
#include <deque>
#include <stdio.h>
#include <cstring>

using namespace std;

#define MAX_SIZE 1000001

int N, K;
int visited[MAX_SIZE];

int bfs()
{
	deque<int> dq;
	dq.push_back(N);
	visited[N] = 1;
	while (!dq.empty())
	{
		int tmp = dq.front();
		dq.pop_front();

		if (tmp == K)
			return visited[K] - 1;

		if (tmp * 2 < MAX_SIZE && !visited[tmp * 2])
		{
			dq.push_front(tmp * 2);
			visited[tmp * 2] = visited[tmp];
		}

		if (tmp + 1 < MAX_SIZE && !visited[tmp + 1])
		{
			dq.push_back(tmp + 1);
			visited[tmp + 1] = visited[tmp] + 1;
		}

		if (tmp - 1 >= 0 && !visited[tmp - 1])
		{
			dq.push_back(tmp - 1);
			visited[tmp - 1] = visited[tmp] + 1;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;

	cout << bfs() << endl;

	return 0;
}