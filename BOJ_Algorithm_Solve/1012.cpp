#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
#define endl '\n'

int testcase;
int m, n, k;
int arr[51][51];
bool visited[51][51];
int ans;
pair<int, int> moveAround[4] = { {1,0},{-1,0},{0,1},{0,-1} };

void init() {
	ans = 0;
	for (int i = 0; i < 51; i++) {
		for (int j = 0; j < 51; j++) {
			arr[i][j] = 0;
			visited[i][j] = false;
		}
	}
}

void bfs(int x,int y) {
	visited[x][y] = true;
	queue<pair<int, int>> q;
	q.push({ x,y });

	while (!q.empty()) {
		int currentX = q.front().first;
		int currentY = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nextX = currentX + moveAround[i].first;
			int nextY = currentY + moveAround[i].second;
			if (0 <= nextX && nextX <= n && 0 <= nextY && nextY <= m) {
				if (visited[nextX][nextY] == false && arr[nextX][nextY] == 1) {
					q.push({ nextX,nextY });
					visited[nextX][nextY] = true;
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> testcase;
	while (testcase--) {
		
		init();

		cin >> m >> n >> k;
		for (int i = 0; i < k; i++) {
			int y, x;
			cin >> y >> x;
			arr[x][y] = 1;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == 1 && visited[i][j] != true) {
					bfs(i, j);
					ans++;
				}
			}
		}

		cout << ans << endl;
	}
	


	return 0;
}