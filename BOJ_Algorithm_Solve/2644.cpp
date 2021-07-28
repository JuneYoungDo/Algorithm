#include<iostream>
#include<queue>
using namespace std;
#define endl '\n'

int ans;
int n, m, a, b;
int map[101][101];
int depth[101];
bool visited[101];

void bfs(int start) {
	queue<int> q;
	q.push(start);
	visited[start] = true;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (map[now][i] && !visited[i]) {
				depth[i] = depth[now] + 1;
				q.push(i);
				visited[i] = true;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	cin >> a >> b;
	cin >> m;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		map[x][y] = 1;
		map[y][x] = 1;
	}
	bfs(a);
	if (depth[b] == 0)
		ans = -1;
	else
		ans = depth[b];
	cout << ans << endl;

	return 0;
}